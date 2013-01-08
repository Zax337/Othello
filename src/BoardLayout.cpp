/*
 * BoardLayout.cpp
 *
 *      Author: Isaline LAURENT
 */

#include "BoardLayout.h"

#define SCORE_COLUMN MAX_SIZE + 2
#define SCORE_LINE BOARD_SIZE - 1
#define START_BUTTON_COLUMN MAX_SIZE + 2
#define START_BUTTON_LINE 1

/**
  * BoardLayout class constructor.
  * \param game A pointer to the game environment.
  * \param parent Parent widget.
  **/
BoardLayout::BoardLayout(OthelloGame *const& game, QWidget * parent) : QGridLayout(parent), _game(game)
{
    _black = QPixmap(BLACK_CELL);
    _white = QPixmap(WHITE_CELL);
    _empty = QPixmap(EMPTY_CELL);
    _allowed = QPixmap(ALLOWED_CELL);
}

/**
  * Initiate a graphic othello grid, with special spaces for score and start button.
  * If the grid already exists, only reconfigure it into first state.
  * \param first Boolean false by default, set to true if this is the first initialization.
  **/
void BoardLayout::initiate(bool first) {
    Cell * label = NULL;
    int midlow = (BOARD_SIZE / 2);
    int midhigh = (BOARD_SIZE / 2) + 1;
    this->setHorizontalSpacing(0);
    this->setVerticalSpacing(0);
    for(int i = 1; i <= BOARD_SIZE; i++) {
        for(int j = 1; j <= BOARD_SIZE; j++) {
            if(first) {
                label = new Cell(i, j, this);
                label->setMinimumSize(50,50);                
                label->setMaximumSize(50,50);
                addWidget(label, i, j);
            } else {
                label = (Cell *) itemAtPosition(i, j)->widget();
            }
            if(i == j && (i == midhigh || i == midlow))
                label->setPixmap(_black);
            else if ((i == midhigh && j == midlow) || (i == midlow && j == midhigh))
                label->setPixmap(_white);
            else
                label->setPixmap(_empty);
        }
    }
    if(first) {
        addWidget(new StartButton(this), START_BUTTON_LINE, START_BUTTON_COLUMN);
        QLabel * score = new QLabel();
        score->setMargin(10);
        addWidget( score, SCORE_LINE, SCORE_COLUMN);
    } else {
        QLabel * score = (QLabel *) itemAtPosition(SCORE_LINE, SCORE_COLUMN)->widget();
        score->hide();
    }
}

/**
  * Change the type of the cell at position (i,j) to \code{type}.
  * \param i Line position.
  * \param j Column position.
  * \param type New type of the cell (black or white).
  **/
void BoardLayout::changeCellType(int i, int j, cellType type) {
    QLabel * cell = (QLabel *) itemAtPosition(i, j)->widget();
    if (type == BLACK)
        cell->setPixmap(_black);
    else if (type == WHITE)
        cell->setPixmap(_white);
}

/**
  * Set the cell at position (i,j) as clickable.
  * \param i Line position.
  * \param j Column position.
  **/
void BoardLayout::setCellClickable(int i, int j) {
    Cell * cell = (Cell *) itemAtPosition(i, j)->widget();
    cell->setClickable(true);
}

/**
  * Set all cells unclickable and change their image to "empty".
  **/
void BoardLayout::setUnclickable() {
    for(int i = 1; i <= BOARD_SIZE; i++) {
        for(int j = 1; j <= BOARD_SIZE; j++) {
            Cell * cell = (Cell *) itemAtPosition(i, j)->widget();
            if(cell->isClickable()) {
                cell->setClickable(false);
                cell->setPixmap(_empty);
            }
        }
    }
}

/**
  * Set all the cells which hold a playable move with the "allowed" image.
  **/
void BoardLayout::setAllowed() {
    for(int i = 1; i <= BOARD_SIZE; i++) {
        for(int j = 1; j <= BOARD_SIZE; j++) {
            Cell * cell = (Cell *) itemAtPosition(i, j)->widget();
            if(cell->isClickable())
                cell->setPixmap(_allowed);
        }
    }
}

/**
  * Compute and show the winner.
  * \param score The difference between the number of black discs and the number of white ones.
  **/
void BoardLayout::win(int score) {
    QLabel * _score = (QLabel *) itemAtPosition(SCORE_LINE, SCORE_COLUMN)->widget();
    if(score == 0) {
        _score->setText("Draw.");
    } else if (score < 0) {
        _score->setText("White wins !");
    } else {
        _score->setText("Black wins !");
    }
    _score->show();
}
