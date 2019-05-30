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
    void run_controller(service::Request* request);
    service::Response get_response();
private:
    std::map <std::string, Controller*> controllers;
    service::Response response;

};


#endif