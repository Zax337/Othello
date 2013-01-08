/*
 * BoardLayout.h
 *
 *      Author: Isaline LAURENT
 */

#ifndef BOARDLAYOUT_H
#define BOARDLAYOUT_H

#include <QGridLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QtGui/QLabel>
#include "OthelloBoard.h"
#include "Cell.h"
#include "defines.h"
#include "OthelloAction.h"
#include "StartButton.h"

#define WHITE_CELL "img/white.png"
#define BLACK_CELL "img/black.png"
#define EMPTY_CELL "img/empty.png"
#define ALLOWED_CELL "img/allowed.png"

class OthelloBoard;

/**
  * This class handles the graphical implementation of the game.
  **/
class BoardLayout : public QGridLayout
{
    Q_OBJECT
private:
    QPixmap _black;
    QPixmap _white;
    QPixmap _empty;
    QPixmap _allowed;
    OthelloGame * _game;

public:
    explicit BoardLayout(OthelloGame * const &game, QWidget * = 0);
    void initiate(bool first);
    void playAction(int i, int j);
    void changeCellType(int i, int j, cellType type);
    void setCellClickable(int i, int j);
    void setUnclickable();
    void setAllowed();
    void start();
    OthelloGame * getGame() {return _game; }
    void win(int score);
};

#endif // BOARDLAYOUT_H
