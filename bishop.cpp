#include "bishop.h"
#include "board.h"
#include <vector>

using namespace std;
Bishop::Bishop(bool color, Board &b):Chesspiece(b) {
    // SetPosition(0,0);
    SetTeam(color);
    type = 'B';
    if (color) { 
        direction = 1;
        type = 'B';
    } else { 
        direction = -1;
        type = 'b';
    }
    board = &b;
}

vector<Position> Bishop::GetMoves() {
    return CheckX();
}