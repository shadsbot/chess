#include "king.h"
#include "board.h"
#include <vector>
#include <algorithm>

using namespace std;
King::King(bool color, Board &b):Chesspiece(b) {
    // SetPosition(0,0);
    SetTeam(color);
    type = 'M';
    if (color) { 
        direction = 1;
        type = 'M';
    } else { 
        direction = -1;
        type = 'm';
    }
    board = &b;
}

vector<Position> King::GetMoves() {
    vector<Position> possiblePositions;
    struct Position newPos = pos;
    newPos.x = pos.x - 1;
    newPos.y = pos.y + 1;
    for(int k = 0; k < 3; k++) {
        newPos.x = pos.x - 1;
        for(int i = 0; i < 3; i++) {
            if (board->IsValid(newPos.x, newPos.y)) {
                if (!board->PieceAt(newPos.x, newPos.y)) {
                    possiblePositions.push_back(newPos);
                }
                if (board->SameTeam(newPos.x, newPos.y, color)) {
                    possiblePositions.push_back(newPos);
                }
            }
            newPos.x++;
        }
        newPos.y--;
    }
    newPos = pos;
    possiblePositions.erase( remove( possiblePositions.begin(), possiblePositions.end(), newPos), possiblePositions.end() );

    return possiblePositions;
}