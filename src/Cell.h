/*
 * Cell.h
 *
 *      Author: Isaline LAURENT
 */

#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QMouseEvent>
#include "BoardLayout.h"

/**
  * This class represents all single cell of the graphic board.
  **/
class Cell : public QLabel
{
    Q_OBJECT
private :
    int _x;
    int _y;
    bool _clickable;
    BoardLayout * _layout;
    void mousePressEvent(QMouseEvent *event);
public:
    Cell(int i, int j, BoardLayout * layout);
    bool isClickable() { return _clickable;}
    void setClickable(bool clickable) { _clickable = clickable;}

signals:
    void clicked(int,int);
};

#endif // CELL_H
