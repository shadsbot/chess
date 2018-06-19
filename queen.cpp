#include "queen.h"
#include "board.h"
#include <vector>

using namespace std;
Queen::Queen(bool color, Board &b):Chesspiece(b) {
    // SetPosition(0,0);
    SetTeam(color);
    type = 'Q';
    if (color) { 
        direction = 1;
        type = 'Q';
    } else { 
        direction = -1;
        type = 'q';
    }
    board = &b;
}

vector<Position> Queen::GetMoves() {
    vector<Position> x = CheckX();
    vector<Position> plus = CheckPlus();
    x.insert(x.end(), plus.begin(), plus.end());
    return x;
}