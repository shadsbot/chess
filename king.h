#ifndef KING_H
#define KING_H

#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

class King: public Chesspiece {
    public:
        King(bool team, Board &b);
        virtual vector<Position> GetMoves();
    private:
        bool testSameTeam(Position position);
};

#endif