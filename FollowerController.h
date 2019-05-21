#ifndef FOLLOWER_CONTROLLER_H
#define FOLLOWER_CONTROLLER_H

#include <vector> 

#include "Controller.h"
#include "UserService.h"

class FollowerController :public Controller
{
public:
    virtual Response post(Request* request);
    virtual Response get(Request* request);
private:
    UserService user_service;
    Response get_follower_response(std::vector <const Client*> clients);
};

#endif