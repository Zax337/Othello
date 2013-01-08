/*
 * Cell.cpp
 *
 *      Author: Isaline LAURENT
 */

#include "Cell.h"

/**
  * Cell constructor. Connect clicked signal with \code{OthelloGame::playAction(int, int)}.
  * The cell is unclickable by default.
  * \param i Line position.
  * \param j Column position.
  * \param layout The layout to which the cell belongs.
  **/
Cell::Cell(int i, int j, BoardLayout * layout) : QLabel(), _x(i), _y(j), _layout(layout)
{
    installEventFilter(this);
    QObject::connect(this, SIGNAL(clicked(int,int)), (QObject*) _layout->getGame(), SLOT(playAction(int,int)));
    _clickable = false;
}

/**
  * Describe the cell behaviour on click.
  **/
void Cell::mousePressEvent(QMouseEvent *event)
{
    // If left button is clicked.
    if (event->button() == Qt::LeftButton)
    {
        if(_clickable) {
            emit clicked(_x,_y);
        } else {
            _layout->setAllowed();
        }
    }
}
