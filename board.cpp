#include <iostream>
#include <algorithm>
#include "board.h"
#include "chesspiece.h"
using namespace std;

Board::Board() {
    Chesspiece * temp = new Chesspiece();
    blank = temp;
    board.resize(8, vector<Chesspiece *>(8, temp));
}

char Board::Cell(int x, int y) {
        return board[y][x]->PieceType();
}

bool Board::PieceAt(int x, int y) {
    if (Cell(x,y) == '_') {
        return false;
    } else {
        return true;
    }
}

bool Board::SameTeam(int x, int y, bool team) {
    return board[y][x]->SameTeam(team);
}

bool Board::IsValid(int x, int y) {
    if (y > 7 || y < 0 || x > 7 || x < 0) {
        return false;
    }
}

void Board::SetPiece(Chesspiece & c) {
    Position square = c.GetPosition();
    board[square.y][square.x] = &c;
}

void Board::PrintBoard() {
    cout << "    0A  1B  2C  3D  4E  5F  6G  7H \n";
    cout << "  +===============================+ \n";
    for(int y = 0; y < 8; y++) {
        cout << y+1 << " |";
        for(int x = 0; x < 8; x++) {
            if ((x + y) % 2 == 0) {
                cout << "_" << Cell(x,y) << "_|";
            } else {
                char a = 35; //#
                a = '_';
                cout << a << Cell(x,y) << a << "|";
            }
        }
        cout << "\n";
    }
    cout << "  +===============================+ \n";
}

void Board::move(int fromX, int fromY, int toX, int toY) {
    Position oldPos = Position(fromX, fromY);
    Position newPos = Position(toX, toY);
    Chesspiece * temp = board[oldPos.y][oldPos.x];
    board[oldPos.y][oldPos.x] = blank;
    vector<Position> validMoves = board[oldPos.y][oldPos.x]->GetMoves();
    // cout << validMoves[0];
    vector<Position>::iterator it;
    it = find(validMoves.begin(), validMoves.end(), newPos);
    if (it != validMoves.end()) {
        if(PieceAt(newPos.x, newPos.y)) {
            cout << "Took " << board[newPos.y][newPos.x]->PieceType() << " at " << newPos << endl;
            delete board[newPos.y][newPos.x];
        }
        board[newPos.y][newPos.x] = temp;
        PrintBoard();
        cout << "Moved " << board[newPos.y][newPos.x]->PieceType() << " from " << oldPos << " to " << newPos << endl;
    } else {
        cout << "Illegal move detected." << endl;
    }
}
