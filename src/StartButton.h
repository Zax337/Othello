/*
 * StartButton.h
 *
 *      Author: Isaline LAURENT
 */

#ifndef STARTBUTTON_H
#define STARTBUTTON_H
#include "BoardLayout.h"

/**
  * Button used to start or restart the game.
  **/
class StartButton : public QPushButton
{
    Q_OBJECT
private:
    BoardLayout * _layout;
public:
    StartButton(BoardLayout * layout);
};

#endif // STARTBUTTON_H
