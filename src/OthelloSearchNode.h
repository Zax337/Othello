/*
 * OthelloSearchNode.h
 *
 *      Author: Isaline LAURENT
 */

#ifndef OTHELLOSEARCHNODE_H
#define OTHELLOSEARCHNODE_H

#include "OthelloBoard.h"

class OthelloAction;

/**
  * Piece of the search tree used for forecasting and action selection.
  **/
class OthelloSearchNode
{
private:
    int _level;
    int _utility;
    OthelloBoard * _board;
    OthelloAction * _action;
    std::list<OthelloSearchNode*> * _children;
public:
    OthelloSearchNode(int level, OthelloBoard *board);
    OthelloSearchNode(int level, OthelloBoard *board, OthelloAction *action);
    ~OthelloSearchNode();
    bool expandNode();
    void setUtility(int utility);
    std::list<OthelloSearchNode*> * getChilds();
    OthelloAction * getActionFromUtility(int utility);
    int getLevel() { return _level; }
    int getUtility() { return _utility; }
    OthelloBoard * getBoard() { return _board;}
};

#endif // OTHELLOSEARCHNODE_H
