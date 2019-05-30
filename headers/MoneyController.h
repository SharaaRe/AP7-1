#ifndef MONEY_CONTROLLER_H
#define MONEY_CONTROLLER_H

#include "Controller.h"

class MoneyController :public Controller
{
public:
    virtual service::Response post(service::Request* request);
    virtual service::Response get(service::Request* request);
};

#endif