#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "chesspiece.h"
#include <memory>
using namespace std;

class Chesspiece; // forward declaration

class Board {
    public:
        Board();
        void PrintBoard();
        char Cell(int x, int y);
        bool PieceAt(int x,int y);
        bool IsValid(int x, int y);
        // void SetPiece(int x, int y, char t);
        void SetPiece(Chesspiece & c);
        bool SameTeam(int x, int y, bool team);
        void move(int fromX, int fromY, int toX, int toY);
    private:
        // char board[8][8];
        Chesspiece * blank;
        vector<vector<Chesspiece *> > board;
};

#endif