/*
 * AIMobility.cpp
 *
 *      Author: Isaline LAURENT
 */

#include "AIMobility.h"
#include "OthelloAction.h"
#include "Tools.hpp"
#define TOTAL BOARD_SIZE * BOARD_SIZE
#define OPENING 8
#define END 40


/**
  * AIMobility class constructor.
  * \param black True if player's color is black, false otherwise.
  * \param game A pointer to the game environment.
  **/
AIMobility::AIMobility(bool black, OthelloGame * game) : AIPlayer(black, game)
{
}

/**
  * The heuristic function which determines the weight of the position.
  * \param board The position to evaluate.
  * \return The position weight according to the heuristic.
  **/
int AIMobility::evaluate(OthelloBoard * board) {
    using namespace std;
    cellType playerColor = (_isBlack) ? BLACK : WHITE;
    cellType opponentColor = (_isBlack) ? WHITE : BLACK;
    OthelloBoard * clone = new OthelloBoard(*board);
    clone->changePlayer();

    list<OthelloAction *> * playerMoves;
    list<OthelloAction *> * opponentMoves;

    // Determine which configuration to use depending of which player started the algorithm.
    if(board->blackIsToPlay() == _isBlack){
        playerMoves = board->getMoves();
        opponentMoves = clone->getMoves();
    } else{
        playerMoves = clone->getMoves();
        opponentMoves = board->getMoves();
    }

    // If the end could be reached.
    if(playerMoves->empty() && opponentMoves->empty()){
        int value = board->getCount(playerColor) - board->getCount(opponentColor);
        int toAdd = 1000000;
        if(value < 0){
            toAdd = -toAdd;
        }
        delete playerMoves;
        delete opponentMoves;
        delete clone;
        return value + toAdd;
    } else{
        int coeffCount;
        int coeffMobility;
        int coeffStability;
        int cloneEmpty = clone->getCount(EMPTY);
        if(TOTAL - cloneEmpty < OPENING){
            coeffCount = 2;
            coeffStability = 85;
            coeffMobility = 10;
        } else if(TOTAL - cloneEmpty >= OPENING && TOTAL - cloneEmpty < END){
            coeffCount = 30;
            coeffStability = 80;
            coeffMobility = 20;
        } else{
            coeffCount = 80;
            coeffStability = 10;
            coeffMobility = 20;
        }
        int discCount = board->getCount(playerColor) - board->getCount(opponentColor);
        int mobilty = playerMoves->size() - opponentMoves->size();
        int stability = (getNumberOfStableDisc(board, playerColor) - getNumberOfStableDisc(board, opponentColor)) * 16 / 3;
        Tools::deleteList(playerMoves);
        Tools::deleteList(opponentMoves);
        delete playerMoves;
        delete opponentMoves;
        delete clone;
        return discCount * coeffCount + stability * coeffStability + mobilty * coeffMobility;
    }
}

/**
     * Get the number of disc which can not be taken by the opponent
     * \param board The current state of the board.
     * \param player Player's color.
     * \return The number of stable discs.
     */
int AIMobility::getNumberOfStableDisc(OthelloBoard * board, cellType player)
{
    return getStableFromCorner(board, player, 1, 1)
            + getStableFromCorner(board, player, 1, BOARD_SIZE)
            + getStableFromCorner(board, player, BOARD_SIZE, 1)
            + getStableFromCorner(board, player, BOARD_SIZE, BOARD_SIZE)
            + getStableFromEdge(board, player, 1, true)
            + getStableFromEdge(board, player, BOARD_SIZE, true)
            + getStableFromEdge(board, player, 1, false)
            + getStableFromEdge(board, player, BOARD_SIZE, false);
}

/**
     * Get the number of stable discs from the edge of the board.
     * \param board the current state of the board.
     * \param player Player's color.
     * \param border Index of the row/column to check.
     * \param isHorizontal True if checking a row, false for a column.
     * \return The number of stable disc on this side.
     */
int AIMobility::getStableFromEdge(OthelloBoard * board, cellType player, int border, bool isHorizontal) {
    int stableDiscs = 0;

    if (isBorderFull(board, border, isHorizontal)) {
        bool opponentDiscPassed = false;
        for (int otherCoordinate = 1; otherCoordinate <= BOARD_SIZE; otherCoordinate++) {
            cellType colorField = (isHorizontal) ? board->getBoard(border,otherCoordinate) : board->getBoard(otherCoordinate,border);
            if (colorField != player){
                opponentDiscPassed = true;
            } else if (opponentDiscPassed) {
                int numberOfconsecutiveDisc = 0;
                while ((otherCoordinate <= BOARD_SIZE) && (colorField == player)) {
                    numberOfconsecutiveDisc++;

                    otherCoordinate++;
                    if (otherCoordinate <= BOARD_SIZE){
                        colorField = (isHorizontal) ? board->getBoard(border, otherCoordinate) : board->getBoard(otherCoordinate,border);
                    }
                }
                if (otherCoordinate != BOARD_SIZE + 1)
                {
                    stableDiscs += numberOfconsecutiveDisc;
                    opponentDiscPassed = true;
                }
            }
        }
    }

    return stableDiscs;
}

/**
     * Check if the edge is full.
     * \param board Current state of the board.
     * \param border Index of the edge to check.
     * \param isHorizontal True if checking a row, false for a column.
     * \return True if border is full.
     */
bool AIMobility::isBorderFull(OthelloBoard * board, int border,	bool isHorizontal) {
    for (int otherCoordinate = 1; otherCoordinate <= BOARD_SIZE; otherCoordinate++){
        if ((isHorizontal && (board->getBoard(border, otherCoordinate) == EMPTY))
                || (!isHorizontal && (board->getBoard(otherCoordinate,border) == EMPTY))){
            return false;
        }
    }
    return true;
}

/**
     * Get the number of disc which can not be taken by the opponent from the corner.
     * \param board Current state of the board.
     * \param player Player's color
     * \param cRowIndex Row index for the corner (can be 1 or board size).
     * \param cColumnIndex Column index for the corner (can be 1 or board size).
     * \return The number of stable discs.
     */
int AIMobility::getStableFromCorner(OthelloBoard * board, cellType player,	int cRowIndex, int cColumnIndex) {
    int stableDiscs = 0;

    int rowChanging = (cRowIndex == 1) ? 1 : -1;
    int columnChanging = (cColumnIndex == 1) ? 1 : -1;

    int row = cRowIndex;
    int rowLimit = (cRowIndex == 1) ? BOARD_SIZE : 1;
    int columnLimit = (cColumnIndex == 1) ? BOARD_SIZE : 1;
    for (row = cRowIndex; row != rowLimit; row += rowChanging){
        int column;
        for (column = cColumnIndex; column != columnLimit + 1; column += columnChanging) {
            if (board->getBoard(row,column) == player) {
                stableDiscs++;
            } else {
                break;
            }
        }
        if ((columnChanging > 0 && column <= BOARD_SIZE) || (columnChanging < 0 && column >= 1)) {
            columnLimit = column - columnChanging;
            if (columnChanging > 0 && columnLimit == 0){
                columnLimit++;
            } else if (columnChanging < 0 && columnLimit == BOARD_SIZE){
                columnLimit--;
            }
            if ((columnChanging > 0 && columnLimit < 0)
                    || (columnChanging < 0 && columnLimit > BOARD_SIZE))
            {
                break;
            }
        }
    }
    return stableDiscs;
}
