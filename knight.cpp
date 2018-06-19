#include "knight.h"
#include "board.h"
#include <vector>

using namespace std;
Knight::Knight() {

}
Knight::Knight(bool color, Board &b):Chesspiece(b) {
    // SetPosition(0,0);
    SetTeam(color);
    type = 'K';
    if (color) { 
        direction = 1;
        type = 'K';
    } else { 
        direction = -1;
        type = 'k';
    }
    board = &b;
}

vector<Position> Knight::GetMoves() {
    vector<Position> possiblePositions;
    struct Position newPos;

    newPos.x = pos.x - 2;
    newPos.y = pos.y + 1;
    if(board->IsValid(newPos.x, newPos.y)) {
        possiblePositions.push_back(newPos);
    }
    newPos.y = pos.y - 1;
    if(board->IsValid(newPos.x, newPos.y)) {
        possiblePositions.push_back(newPos);
    }

    newPos.x = pos.x - 1;
    newPos.y = pos.y + 2;
    if(board->IsValid(newPos.x, newPos.y)) {
        possiblePositions.push_back(newPos);
    }
    newPos.y = pos.y - 2;
    if(board->IsValid(newPos.x, newPos.y)) {
        possiblePositions.push_back(newPos);
    }

    newPos.x = pos.x + 1;
    newPos.y = pos.y + 2;
    if(board->IsValid(newPos.x, newPos.y)) {
        possiblePositions.push_back(newPos);
    }
    newPos.y = pos.y - 2;
    if(board->IsValid(newPos.x, newPos.y)) {
        possiblePositions.push_back(newPos);
    }

    newPos.x = pos.x + 2;
    newPos.y = pos.y + 1;
    if(board->IsValid(newPos.x, newPos.y)) {
        possiblePositions.push_back(newPos);
    }
    newPos.y = pos.y - 1;
    if(board->IsValid(newPos.x, newPos.y)) {
        possiblePositions.push_back(newPos);
    }

    return possiblePositions;
}
