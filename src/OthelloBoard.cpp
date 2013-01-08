/*
 * OthelloBoard.cpp
 *
 *      Author: Isaline LAURENT
 */

#include "OthelloBoard.h"
#include "BoardLayout.h"
#include "OthelloAction.h"
#include "AIMobility.h"
#include "Human.h"

#define DIAG1 0x80
#define DIAG2 0x20
#define DIAG3 0x8
#define DIAG4 0x2
#define LINE1 0x40
#define LINE2 0x10
#define LINE3 0x4
#define LINE4 0x1

/**
  * OthelloBoard class constructor.
  **/
OthelloBoard::OthelloBoard() {
    _board = new cellType[MAX_SIZE * MAX_SIZE];
}

/**
  * OthelloBoard class copy constructor.
  * \param board Reference to the board to copy.
  **/
OthelloBoard::OthelloBoard(OthelloBoard & board) {
    _blackIsToPlay = board._blackIsToPlay;
    _pass = board._pass;
    _board = new cellType[MAX_SIZE * MAX_SIZE];
    memcpy(_board, board._board, MAX_SIZE * MAX_SIZE * sizeof(cellType));
}

OthelloBoard::~OthelloBoard() {
    delete[] _board;
}

/**
  * Initiate the board. Memory must be already allocated.
  **/
void OthelloBoard::initiate() {
    _blackIsToPlay = true;
    _pass = false;
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            _board[(i * MAX_SIZE) + j] = EMPTY;
        }
    }
    int midlow = (BOARD_SIZE / 2);
    int midhigh = (BOARD_SIZE / 2) + 1;
    _board[midhigh * MAX_SIZE + midhigh] = _board[midlow * MAX_SIZE + midlow] = BLACK;
    _board[midhigh * MAX_SIZE + midlow] = _board[midlow * MAX_SIZE + midhigh] = WHITE;
}

/**
  * Get the possible moves in the current configuration of the board.
  * \return A list of OthelloAction pointers representing the legal moves.
  **/
std::list<OthelloAction *> * OthelloBoard::getMoves() {
    using namespace std;
    list<OthelloAction *> * actions = new list<OthelloAction *>();
    cellType playerColor = (_blackIsToPlay) ? BLACK : WHITE;
    cellType opponentColor = (_blackIsToPlay) ? WHITE : BLACK;
    char directions;
    for(int i = 1; i <= BOARD_SIZE; i++) {
        for(int j = 1; j <= BOARD_SIZE; j++) {
            directions = canStartMove(i, j, playerColor, opponentColor);

            if(directions & DIAG1)
                getMovesInDiag(i, j, opponentColor, actions, true, true);
            if(directions & DIAG2)
                getMovesInDiag(i, j, opponentColor, actions, true, false);
            if(directions & DIAG3)
                getMovesInDiag(i, j, opponentColor, actions, false, false);
            if(directions & DIAG4)
                getMovesInDiag(i, j, opponentColor, actions, false, true);

            if(directions & LINE1)
                getMovesInCol(i, j, opponentColor, actions, true);
            if(directions & LINE2)
                getMovesInLine(i, j, opponentColor, actions, false);
            if(directions & LINE3)
                getMovesInCol(i, j, opponentColor, actions, false);
            if(directions & LINE4)
                getMovesInLine(i, j, opponentColor, actions, true);
        }
    }
    return actions;
}

/**
  * Return a mask of 8 bytes. Each bit is set to one if and only if the player can start a move in this position.
  * The first bit corresponds to the top left diagonal, and so on in clockwise.
  **/
char OthelloBoard::canStartMove(int i, int j, cellType player, cellType opponent) {
    char mask = 0x0;
    if(_board[i * MAX_SIZE + j] == player) {
        mask = (_board[(i-1) * MAX_SIZE + (j-1)] == opponent) ? (mask | 1) << 1 : mask << 1; // DIAG1
        mask = (_board[(i-1) * MAX_SIZE + j]   == opponent) ? (mask | 1) << 1 : mask << 1; // LINE1
        mask = (_board[(i-1) * MAX_SIZE + (j+1)] == opponent) ? (mask | 1) << 1 : mask << 1; // DIAG2
        mask = (_board[i * MAX_SIZE + (j+1)]   == opponent) ? (mask | 1) << 1 : mask << 1; // LINE2
        mask = (_board[(i+1) * MAX_SIZE + (j+1)] == opponent) ? (mask | 1) << 1 : mask << 1; // DIAG3
        mask = (_board[(i+1) * MAX_SIZE + j]   == opponent) ? (mask | 1) << 1 : mask << 1; // LINE3
        mask = (_board[(i+1) * MAX_SIZE + (j-1)] == opponent) ? (mask | 1) << 1 : mask << 1; // DIAG4
        if(_board[i * MAX_SIZE + (j-1)]   == opponent) mask = (mask | 1); // LINE4
    }
    return mask;
}

/**
  * Get possible move in line from a given position (X,Y). The direction is given by the left parameter.
  **/
void OthelloBoard::getMovesInLine(int X, int Y, cellType opponent, std::list<OthelloAction *> * &moves, bool left) {
    using namespace std;
    int k = left ? -1 : 1;
    int i = Y + k;
    int ilimit = left ? 1 : BOARD_SIZE;
    while(abs(i - ilimit) > 0 && _board[X * MAX_SIZE + i] == opponent){
        i += k;
    }
    if(abs(i - ilimit) >= 0 && abs(i - (Y + k)) > 0 && _board[X * MAX_SIZE + i] == EMPTY){
        moves->push_back(new OthelloAction(X, i));
    }
}

/**
  * Get possible move in column from a given position (X,Y). The direction is given by the top parameter.
  **/
void OthelloBoard::getMovesInCol(int X, int Y, cellType opponent, std::list<OthelloAction *> * &moves, bool top) {
    using namespace std;
    int k = top ? -1 : 1;
    int i = X + k;
    int ilimit = top ? 1 : BOARD_SIZE;
    while(abs(i - ilimit) > 0 && _board[i * MAX_SIZE + Y] == opponent){
        i += k;
    }
    if(abs(i - ilimit) >= 0 && abs(i - (X + k)) > 0 && _board[i * MAX_SIZE + Y] == EMPTY){
        moves->push_back(new OthelloAction(i, Y));
    }
}

/**
  * Get possible move in diagonal from a given position (X,Y). The direction is given by the left and top parameters.
  **/
void OthelloBoard::getMovesInDiag(int X, int Y, cellType opponent, std::list<OthelloAction *> * &moves, bool top, bool left) {
    using namespace std;
    int k, l;
    int ilimit, jlimit;
    k = top ? -1 : 1;
    ilimit = (top) ? 1 : BOARD_SIZE;
    l = left ? -1 : 1;
    jlimit = (left) ? 1 : BOARD_SIZE;

    bool done = false;
    int i = X + k;
    int j = Y + l;
    while(abs(j - jlimit) > 0 && abs(i - ilimit) > 0 && _board[i * MAX_SIZE + j] == opponent){
        i += k;
        j += l;
        done = true;
    }
    if(abs(j - jlimit) >= 0 && abs(i - ilimit) >= 0 && done && _board[i * MAX_SIZE + j] == EMPTY){
        moves->push_back(new OthelloAction(i, j));
    }
}

/**
  * Set the type of the cell at position (i,j) to \code{type}.
  * \param i Line position.
  * \param j Column position.
  * \param type New type of the cell.
  **/
void OthelloBoard::setCell(int i, int j, cellType type) {
    _board[i * MAX_SIZE + j] = type;
}

/**
  * Get the number of the cells of the type \code{type}.
  * \param type Type to count.
  **/
int OthelloBoard::getCount(cellType type) {
    int count = 0;
    for(int i = 1; i < BOARD_SIZE; i++) {
        for(int j = 1; j < BOARD_SIZE; j++) {
            if(_board[i * MAX_SIZE + j] == type)
                count++;
        }
    }
    return count;
}

/**
  * Change player.
  **/
void OthelloBoard::changePlayer() {
    _blackIsToPlay = !_blackIsToPlay;
}
