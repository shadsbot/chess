#include <iostream>
#include "chesspiece.h"
#include "pawn.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "board.h"
#include <vector>

using namespace std;

void setUpBoard(vector<Chesspiece*> &p, Board &k);

int main() {
    Board * k = new Board();
    vector<Chesspiece*> pieces;
    setUpBoard(pieces, *k);
    
    // Testing block: not final, to be removed
    // Pawn * j = new Pawn(true, *k);
    // j->SetPosition(5,4);

    // vector<Position>::iterator It;
    // vector<Position> x = j->GetMoves();
    // for(It = x.begin(); It != x.end(); ++It) {
    //     cout << *It << '\t';
    // }

    // cout << endl;

    k->PrintBoard();

    return 0; 
}

void setUpBoard(vector<Chesspiece*> &p, Board &k) {
    p.clear();
    for (int i = 0; i < 8; i++) {
        p.push_back(new Pawn(true, k));
    }
    for (int i = 0; i < 8; i++) {
        p.push_back(new Pawn(false, k));
    }
    for (int i = 0; i < 8; i++) {
        p[i]->SetPosition(i,1);
        p[i+8]->SetPosition(i,6);
    }
    p.push_back(new Knight(false, k));
    p.back()->SetPosition(1,0);
    p.push_back(new Knight(false, k));
    p.back()->SetPosition(6,0);
    p.push_back(new Knight(true, k));
    p.back()->SetPosition(1,7);
    p.push_back(new Knight(true, k));
    p.back()->SetPosition(6,7);
    
    p.push_back(new Rook(false, k));
    p.back()->SetPosition(0,0);
    p.push_back(new Rook(false, k));
    p.back()->SetPosition(7,0);
    p.push_back(new Rook(true, k));
    p.back()->SetPosition(0,7);
    p.push_back(new Rook(true, k));
    p.back()->SetPosition(7,7);

    p.push_back(new Bishop(false, k));
    p.back()->SetPosition(2,0);
    p.push_back(new Bishop(false, k));
    p.back()->SetPosition(5,0);
    p.push_back(new Bishop(true, k));
    p.back()->SetPosition(2,7);
    p.push_back(new Bishop(true, k));
    p.back()->SetPosition(5,7);

    p.push_back(new Queen(false, k));
    p.back()->SetPosition(3,0);
    p.push_back(new Queen(true, k));
    p.back()->SetPosition(3,7);

    p.push_back(new King(false, k));
    p.back()->SetPosition(4,0);
    p.push_back(new King(true, k));
    p.back()->SetPosition(4,7);

}