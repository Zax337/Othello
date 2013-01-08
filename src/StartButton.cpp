/*
 * StartButton.cpp
 *
 *      Author: Isaline LAURENT
 */

#include "StartButton.h"

/**
  * Create a "start" button which starts or restarts the game when clicked.
  **/
StartButton::StartButton(BoardLayout *layout) : QPushButton("Start"), _layout(layout)
{
    QObject::connect(this, SIGNAL(clicked()), _layout->getGame(), SLOT(start()));
}
