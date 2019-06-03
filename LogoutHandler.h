#ifndef LOGOUT_HANDLER_H
#define LOGOUT_HANDLER_H

#include "server.hpp"

class LogoutHandler: public RequestHandler
{
public:
    LogoutHandler() = default;
    Response* callback(Request*);
};

#endif