#include "chesspiece.h"
#include "board.h"
#include <vector>

using namespace std;

Chesspiece::Chesspiece() {
    // Blank chesspiece
}

Chesspiece::Chesspiece(Board &b) {
    board = &b;
}
Chesspiece::~Chesspiece() {

}

char Chesspiece::PieceType() {
    return type;
}

Position Chesspiece::GetPosition() {
    return pos;
}

void Chesspiece::SetPosition(int x, int y) {
    pos.x = x;
    pos.y = y;
    // board->SetPiece(x, y, type);
    board->SetPiece(*this);
}

vector<Position> Chesspiece::CheckPlus() {
    vector<Position> possiblePositions;
    struct Position newPos = pos;

    // Right
    newPos.x = pos.x+1;
    newPos.y = pos.y;
    while(board->IsValid(newPos.x, newPos.y)) {
        if (board->PieceAt(newPos.x, newPos.y)) {
            if (!board->SameTeam(newPos.x,newPos.y, color)) {
                possiblePositions.push_back(newPos);
                break;
            }
            break;
        }
        possiblePositions.push_back(newPos);
        newPos.x++;
    }
    // Left
    newPos.x = pos.x - 1;
    newPos.y = pos.y;
    while(board->IsValid(newPos.x, newPos.y)) {
        if (board->PieceAt(newPos.x, newPos.y)) {
            if (!board->SameTeam(newPos.x,newPos.y, color)) {
                possiblePositions.push_back(newPos);
                break;
            }
            break;
        }
        possiblePositions.push_back(newPos);
        newPos.x--;
    }
    // Up
    newPos.x = pos.x;
    newPos.y = pos.y + 1;
    while(board->IsValid(newPos.x, newPos.y)) {
        if (board->PieceAt(newPos.x, newPos.y)) {
            if (!board->SameTeam(newPos.x,newPos.y, color)) {
                possiblePositions.push_back(newPos);
                break;
            }
            break;
        }
        possiblePositions.push_back(newPos);
        newPos.y++;
    }
    // Down
    newPos.x = pos.x;
    newPos.y = pos.y - 1;
    while(board->IsValid(newPos.x, newPos.y)) {
        if (board->PieceAt(newPos.x, newPos.y)) {
            if (!board->SameTeam(newPos.x,newPos.y, color)) {
                possiblePositions.push_back(newPos);
                break;
            }
            break;
        }
        possiblePositions.push_back(newPos);
        newPos.y--;
    }

    return possiblePositions;
}

vector<Position> Chesspiece::GetMoves() {
    vector<Position> possiblePositions;
    struct Position newPos = pos;
    return possiblePositions;
}

vector<Position> Chesspiece::CheckX() {
    vector<Position> possiblePositions;
    struct Position newPos = pos;

    newPos.x = pos.x - 1;
    newPos.y = pos.y - 1;
    while(board->IsValid(newPos.x, newPos.y)) {
        if (board->PieceAt(newPos.x, newPos.y)) {
            if (!board->SameTeam(newPos.x,newPos.y, color)) {
                possiblePositions.push_back(newPos);
                break;
            }
            break;
        }
        possiblePositions.push_back(newPos);
        newPos.x--;
        newPos.y--;
    }
    newPos.x = pos.x - 1;
    newPos.y = pos.y + 1;
    while(board->IsValid(newPos.x, newPos.y)) {
        if (board->PieceAt(newPos.x, newPos.y)) {
            if (!board->SameTeam(newPos.x,newPos.y, color)) {
                possiblePositions.push_back(newPos);
                break;
            }
            break;
        }
        possiblePositions.push_back(newPos);
        newPos.x--;
        newPos.y++;
    }
    newPos.x = pos.x + 1;
    newPos.y = pos.y + 1;
    while(board->IsValid(newPos.x, newPos.y)) {
        if (board->PieceAt(newPos.x, newPos.y)) {
            if (!board->SameTeam(newPos.x,newPos.y, color)) {
                possiblePositions.push_back(newPos);
                break;
            }
            break;
        }
        possiblePositions.push_back(newPos);
        newPos.x++;
        newPos.y++;
    }
    newPos.x = pos.x + 1;
    newPos.y = pos.y - 1;
    while(board->IsValid(newPos.x, newPos.y)) {
        if (board->PieceAt(newPos.x, newPos.y)) {
            if (!board->SameTeam(newPos.x,newPos.y, color)) {
                possiblePositions.push_back(newPos);
                break;
            }
            break;
        }
        possiblePositions.push_back(newPos);
        newPos.x++;
        newPos.y--;
    }

    return possiblePositions;
}