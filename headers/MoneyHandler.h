#ifndef MONEY_HANDLER_H
#define MONEY_HANDLER_H

#include "server.hpp"

class MoneyHandler: public RequestHandler
{
public:
    Response* callback(Request*);
    
};


#endif