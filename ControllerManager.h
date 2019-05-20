#ifndef CONTROLLER_MANAGER_H
#define CONTROLLER_MANAGER_H

#include <map>
#include <string>

#include "Controller.h"
#include "Request.h"
#include "Response.h"

class ControllerManager 
{
public:
    ControllerManager();
    ~ControllerManager();
    void run_controller(Request* request);
    Response get_response();
private:
    std::map <std::string, Controller*> controllers;
    Response response;

};


#endif