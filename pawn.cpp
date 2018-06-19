#include "chesspiece.h"
#include "pawn.h"
#include "board.h"
#include <vector>

using namespace std;

Pawn::Pawn(bool color, Board &b):Chesspiece(b) {
    // SetPosition(0,0);
    SetTeam(color);
    if (color) { 
        direction = 1;
        type = 'p';
    } else { 
        direction = -1; 
        type = 'P';
    }
    board = &b;
}

vector<Position> Pawn::GetMoves() {
    vector<Position> possiblePositions;
    struct Position newPos;
    newPos.x = pos.x;
    if(board->IsValid(newPos.x, newPos.y+1)) {
        newPos.y = pos.y + (1*direction);
    }
    if(!board->PieceAt(pos.x, pos.y + direction)) {
        possiblePositions.insert( possiblePositions.begin(), newPos );
    }

    return possiblePositions;
}