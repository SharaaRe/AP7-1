#ifndef LOGOUT_CONTROLLER_H
#define LOGOUT_CONTROLLER_H

#include "Controller.h"
#include "UserSessionManagement.h"

class LogoutController: public Controller
{
public:
    LogoutController();
    service::Response post(service::Request*);
private: 
    UserSessionManagement* user_manager;

};

#endif