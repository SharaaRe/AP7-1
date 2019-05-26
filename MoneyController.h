#ifndef MONEY_CONTROLLER_H
#define MONEY_CONTROLLER_H

#include "Controller.h"

class MoneyController :public Controller
{
public:
    virtual Response post(Request* request);
    virtual Response get(Request* request);
};

#endif