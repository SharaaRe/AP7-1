#ifndef FOLLOWER_CONTROLLER_H
#define FOLLOWER_CONTROLLER_H

#include <vector> 

#include "Controller.h"
#include "UserService.h"

class FollowerController :public Controller
{
public:
    virtual service::Response post(service::Request* request);
    virtual service::Response get(service::Request* request);
private:
    UserService user_service;
    service::Response get_follower_response(std::vector <const Client*> clients);
};

#endif