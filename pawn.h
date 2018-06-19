#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include <vector>
#include "chesspiece.h"
using namespace std;

class Pawn: public Chesspiece {
    public:
        Pawn(bool team, Board &b);
        virtual vector<Position> GetMoves();
    // protected:
};

#endif