#ifndef BUY_HANDLER_H
#define BUY_HANDLER_H

#include "server.hpp"


class BuyHandler: public RequestHandler
{
public:
    Response* callback(Request* req);
};

#endif