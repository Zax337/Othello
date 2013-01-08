/*
 * OthelloBoard.h
 *
 *      Author: Isaline LAURENT
 */

#ifndef OTHELLOBOARD_H_
#define OTHELLOBOARD_H_

#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QGridLayout>
#include "defines.h"
#include "Player.h"
#include "BoardInterface.h"

class BoardLayout;
class OthelloAction;

/**
  * Intern representation of game board.
  **/
class OthelloBoard : public BoardInterface {
private:
    cellType * _board;
	bool _blackIsToPlay;
    bool _pass;
    char canStartMove(int i, int j, cellType player, cellType opponent);
    void getMovesInLine(int i, int j, cellType, std::list<OthelloAction *> * &moves, bool);
    void getMovesInCol(int i, int j, cellType, std::list<OthelloAction *> * &moves, bool);
    void getMovesInDiag(int i, int j, cellType, std::list<OthelloAction *> * &moves, bool, bool);
public:
	OthelloBoard();
    OthelloBoard(OthelloBoard &board);
	~OthelloBoard();
    std::list<OthelloAction *> * getMoves();
    int getCount(cellType type);
    void initiate();
    void changePlayer();
    OthelloBoard * getBoard() { return this;}
    void setCell(int i, int j, cellType type);
    bool blackIsToPlay() { return _blackIsToPlay;}
    cellType getBoard(int i, int j) { return _board[i * MAX_SIZE + j];}
    void pass(bool b) { _pass = b;}
    bool pass() {return _pass;}
};

#endif /* OTHELLOBOARD_H_ */
