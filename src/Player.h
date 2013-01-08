/*
 * Player.h
 *
 *      Author: Isaline LAURENT
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "defines.h"
#include <QObject>

class OthelloGame;
class OthelloAction;

/**
  * Basic player class. Each player must implement the \code{play} function, which describe actions played at each turn.
  **/
class Player : public QObject
{
    Q_OBJECT
protected:
    bool _isBlack;
    OthelloGame * _game;
public:
    Player(bool black, OthelloGame * game) : _isBlack(black), _game(game) {
        QObject::connect(this, SIGNAL(pass(int,int)), (QObject *) _game, SLOT(playAction(int,int)));
    }
    virtual void play(OthelloGame *) = 0;
signals:
    void pass(int,int);
};

#endif // PLAYER_H
