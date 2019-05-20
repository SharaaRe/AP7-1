#ifndef SIGNUP_CONTROLLER_H
#define SIGNUP_CONTROLLER_H

#include "Controller.h"

class SignupController: public Controller
{
public:
    virtual Response post(Request* request);

protected:
    std::string username;
    std::string password;
    std::string email;
    int age;
    bool publisher_flag;
    void post_required_params();
    bool is_publisher();

};


#endif