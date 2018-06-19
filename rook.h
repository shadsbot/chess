#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

class Rook: public Chesspiece {
    public:
        Rook(bool team, Board &b);
        vector<Position> GetMoves();
    // protected:
};

#endif