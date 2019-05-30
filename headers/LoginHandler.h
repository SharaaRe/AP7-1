#ifndef LOGIN_HANDLER_H
#define LOGIN_HANDLER_H

#include "server.hpp"

class LoginHandler :public RequestHandler
{
    public:
        virtual Response* callback(Request* req);
    private:
        std::string username;
        std::string password;
        virtual void required_params();
};

#endif