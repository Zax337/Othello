/*
 * OthelloAction.h
 *
 *      Author: Isaline LAURENT
 */

#ifndef OTHELLOACTION_H_
#define OTHELLOACTION_H_

#include "OthelloGame.h"
#include "defines.h"
#include "BoardInterface.h"

/**
  * OthelloAction are represented by their coordinates.
  * (-1, -1) is a pass move.
  **/
class OthelloAction {
private :
	int _x;
    int _y;

public:
	OthelloAction(int i, int j);
	~OthelloAction();
	int getX();
    int getY();
    void apply(BoardInterface * const &);
private:
    void getChangesInLine(OthelloBoard * board, cellType opponent, std::list<OthelloAction *> * &actions);
    void getChangesInCol(OthelloBoard * board, cellType opponent, std::list<OthelloAction *> * &actions);
    void getChangesInDiag(OthelloBoard * board, cellType opponent, std::list<OthelloAction *> * &actions);
    void getChangesInDiagAux(OthelloBoard *, cellType, std::list<OthelloAction *> * &, int, int, int, int);
    void getChangesInLineAux(OthelloBoard *, cellType, std::list<OthelloAction *> * &, int , int);
    void getChangesInColAux(OthelloBoard *, cellType, std::list<OthelloAction *> * &, int , int);
};

#endif /* OTHELLOACTION_H_ */
