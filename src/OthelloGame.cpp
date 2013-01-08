/*
 * OthelloGame.cpp
 *
 *      Author: Isaline LAURENT
 */

#include "OthelloGame.h"
#include "OthelloAction.h"
#include "AIMobility.h"
#include "Human.h"

/**
  * OthelloGame class constructor.
  **/
OthelloGame::OthelloGame()
{
    _layout = new BoardLayout(this);
    _black = new Human(true, this);
    _white = new AIMobility(false, this);
    _board = new OthelloBoard();
}

/**
  * Initiate the game.
  * \param first Set to true if initialization must allocate memory.
  **/
void OthelloGame::initiate(bool first) {
    _board->initiate();
    _layout->initiate(first);
}

/**
  * Get the layout.
  **/
QLayout * OthelloGame::getLayout() {
    return _layout;
}

/**
  * Get possible moves in the current state of the game.
  * \return A list of pointers of the possible OthelloAction.
  **/
std::list<OthelloAction *> * OthelloGame::getMoves() {
    return _board->getMoves();
}

/**
  * Set the cell to the type \code{code}. Change are made both in the board and the layout.
  * \param i Line position.
  * \param j Column position.
  * \param type The new type of the cell.
  **/
void OthelloGame::setCell(int i, int j, cellType type) {
    _board->setCell(i, j, type);
    _layout->changeCellType(i, j, type);
}

/**
  * Make the current player plays.
  **/
void OthelloGame::play() {
    _board->blackIsToPlay() ? _black->play(this) : _white->play(this);
}

/**
  * Start or restart the game, i.e initiate the board and make the first player begin.
  * \param first Set to true if this is the first game.
  **/
void OthelloGame::start(bool first) {
    initiate(first);
    play();
}

/**
  * Set the cells corresponding to the OthelloAction given in the list as clickable cells.
  * \param allowed List of pointers of OthelloAction.
  **/
void OthelloGame::setClickableMoves(std::list<OthelloAction *> * &allowed ) {
    using namespace std;

    for(list<OthelloAction*>::iterator it = allowed->begin(); it != allowed->end(); ++it) {
        _layout->setCellClickable((*it)->getX(), (*it)->getY());
    }
}

/**
  * Set the whole board unclickable.
  **/
void OthelloGame::setUnclickable() {
    _layout->setUnclickable();
}

/**
  * \return OthelloBoard to the board.
  **/
OthelloBoard * OthelloGame::getBoard() {
    return _board;
}

/**
  * Test whether the end is reached.
  * \return True if the end is reached, false otherwise.
  **/
bool OthelloGame::isThatTheEnd() {
    if(_board->pass()) {
        return true;
    } else {
        _board->pass(true);
        return false;
    }
}

/**
  * Count the number of cells of each color and make the layout announce the winner.
  **/
void OthelloGame::theEnd() {
    int black = _board->getCount(BLACK);
    int white = _board->getCount(WHITE);
    _layout->win(black - white);
}

/**
  * Change the player and make the new current player play.
  **/
void OthelloGame::nextTurn() {
    _board->changePlayer();
    play();
}

/**
  * Play the given action.
  * If x and y are equal to -1, this is a pass move.
  * \param x Line position of the disc to play.
  * \param y Column position of the disc to play.
  **/
void OthelloGame::playAction(int x,int y) {
    if(x == -1 && y == -1) {
        if(isThatTheEnd()) {
            theEnd();
        } else {
            nextTurn();
        }
    } else {
        OthelloAction action = OthelloAction(x,y);
        setUnclickable();
        action.apply(this);
        nextTurn();
    }
}
