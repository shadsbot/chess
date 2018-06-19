#include "rook.h"
#include "board.h"
#include <vector>

using namespace std;
Rook::Rook(bool color, Board &b):Chesspiece(b) {
    // SetPosition(0,0);
    SetTeam(color);
    type = 'R';
    if (color) { 
        direction = 1;
        type = 'R';
    } else { 
        direction = -1;
        type = 'r';
    }
    board = &b;
}

vector<Position> Rook::GetMoves() {
    return CheckPlus();
}