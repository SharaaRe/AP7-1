#ifndef LOGOUT_CONTROLLER_H
#define LOGOUT_CONTROLLER_H

#include "Controller.h"
#include "UserSessionManagement.h"

class LogoutController: public Controller
{
public:
    LogoutController();
    Response post(Request*);
private: 
    UserSessionManagement* user_manager;

};

#endif