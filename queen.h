#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

class Queen: public Chesspiece {
    public:
        Queen(bool team, Board &b);
        vector<Position> GetMoves();
    // protected:
};

#endif