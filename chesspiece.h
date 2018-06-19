#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

struct Position {
    int x = 0;
    int y = 0;

    Position(int x=0, int y=0) : x(x), y(y) {}
    
    Position& operator=(const Position& a) {
        x = a.x;
        y = a.y;
        return *this;
    }
    bool operator==(const Position& a) {
        return (x == a.x) && (y == a.y);
    }
};

inline ostream& operator << (ostream &o, const Position &a) {
    char lut[8] = {'A','B','C','D','E','F','G','H'};
    o << "[" << lut[a.x] << "," << a.y+1 << "]"; // Print a Position as [x,y]
    // o << "[" << a.x << "," << a.y << "]"; // Print a Position as [x,y]
    return o;
}

class Board; // forward declaration

class Chesspiece {
    public:
        Chesspiece();
        ~Chesspiece();
        Chesspiece(Board &b);
        void SetPosition(int positionX, int positionY);
        void SetTeam(bool team) { 
            color = team;
        }
        Position GetPosition();
        char PieceType();
        bool SameTeam(bool testTeam) {
            return color == testTeam;
        }
        virtual vector<Position> GetMoves();
    protected:
        Position pos;
        bool color;
        Board * board;
        char type = '_';
        int direction;
        vector<Position> CheckPlus();
        vector<Position> CheckX();
};

#endif
