/*
 * OthelloGame.h
 *
 *      Author: Isaline LAURENT
 */

#ifndef OTHELLOGAME_H
#define OTHELLOGAME_H

#include "OthelloBoard.h"
#include "BoardLayout.h"
#include "defines.h"
#include "Player.h"
#include "BoardInterface.h"
#include <QObject>

/**
  * Game master class.
  **/
class OthelloGame : public QObject, public BoardInterface
{
    Q_OBJECT
private:
    BoardLayout * _layout;
    OthelloBoard * _board;
    Player * _white;
    Player * _black;
    bool isThatTheEnd();
    void theEnd();
    void nextTurn();
    void play();
public:
    OthelloGame();
    QLayout * getLayout();
    void setCell(int i, int j, cellType type);
    cellType getBoard(int i, int j);
    OthelloBoard * getBoard();
    void setClickableMoves(std::list<OthelloAction*> *&allowed);
    void setUnclickable();
    void initiate(bool first);
    void changePlayer();
    std::list<OthelloAction *> * getMoves();

public slots :
    void playAction(int x, int y);
    void start(bool = false);
};

#endif // OTHELLOGAME_H
