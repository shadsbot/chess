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
    newPos.y = pos.y + direction;
    if(!board->IsValid(newPos.x, newPos.y)) {
        newPos.y = pos.y;
    }
    if(!board->PieceAt(pos.x, pos.y + direction)) {
        possiblePositions.insert( possiblePositions.begin(), newPos );
    }
    return possiblePositions;
}