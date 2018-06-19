#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <vector>
#include "chesspiece.h"
using namespace std;

class Knight: public Chesspiece {
    public:
        Knight();
        Knight(bool team, Board &b);
        vector<Position> GetMoves();
};

#endif