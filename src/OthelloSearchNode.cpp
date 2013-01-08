/*
 * OthelloSearchNode.cpp
 *
 *      Author: Isaline LAURENT
 */

#include "OthelloSearchNode.h"
#include "OthelloAction.h"
#include "Tools.hpp"

/**
  * OthelloSearchNode class constructor.
  * \param level Depth of the new node. Root level is 0.
  * \param board State of the board for this node.
  **/
OthelloSearchNode::OthelloSearchNode(int level, OthelloBoard * board) :
    _level(level), _utility(0), _action(NULL), _children(NULL)
{
    _board = new OthelloBoard(*board);
}

/**
  * OthelloSearchNode class constructor.
  * \param level Depth of the new node. Root level is 0.
  * \param board State of the board for this node.
  * \param action Action made to reach this state for the parent.
  **/
OthelloSearchNode::OthelloSearchNode(int level, OthelloBoard * board, OthelloAction * action) :
    _level(level), _utility(0), _board(board), _action(action), _children(NULL)
{
}

/**
  * OthelloSearchNode destructor.
  * Recursively delete the children of the node.
  **/
OthelloSearchNode::~OthelloSearchNode() {
    if(_action != NULL) {
        delete _action;
    }
    delete _board;
    if(_children != NULL) {
        Tools::deleteList(_children);
        delete _children;
    }
}

/**
  * Create the children of the node, corresponding to all possible moves from node board.
  * \return True if the node has been expand, false if no move was possible.
  **/
bool OthelloSearchNode::expandNode() {
    using namespace std;
    list<OthelloAction*> * moves = _board->getMoves();
    if(moves == NULL)
        return false;

    _children = new list<OthelloSearchNode*>();
    for(list<OthelloAction*>::iterator it = moves->begin(); it != moves->end(); ++it) {
        OthelloBoard * p = new OthelloBoard(*_board);
        (*it)->apply(p);
        p->changePlayer();
        _children->push_front(new OthelloSearchNode(_level + 1, p, *it));
    }
    delete moves;
    return true;
}

/**
  * Search in the children the one which has an utility equal to \code{utility}.
  * \return The corresponding node, or NULL if none.
  **/
OthelloAction * OthelloSearchNode::getActionFromUtility(int utility){
    using namespace std;
    OthelloAction * action = NULL;
    if(_children != NULL) {
        for(list<OthelloSearchNode*>::iterator it = _children->begin(); it != _children->end(); ++it) {
            if((*it)->_utility == utility){
                action = (*it)->_action;
            }
        }
    }
    return action;
}

void OthelloSearchNode::setUtility(int utility) {
    _utility = utility;
}

std::list<OthelloSearchNode*> * OthelloSearchNode::getChilds() {
    return _children;
}
