#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

class Bishop: public Chesspiece {
    public:
        Bishop(bool team, Board &b);
        vector<Position> GetMoves();
    // protected:
};

#endif