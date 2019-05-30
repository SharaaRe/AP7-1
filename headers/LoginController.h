#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include "Controller.h"
#include "Response.h"

class LoginController :public Controller
{
    public:
        virtual service::Response post(service::Request* request);
    private:
        virtual void post_required_params();
};

#endif