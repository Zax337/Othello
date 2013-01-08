#ifndef BOARDINTERFACE_H
#define BOARDINTERFACE_H
#include "defines.h"

class BoardInterface {
public :
    virtual void setCell(int i, int j, cellType type) = 0;
};

#endif // BOARDINTERFACE_H
