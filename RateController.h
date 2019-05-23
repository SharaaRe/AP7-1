#ifndef RATE_CONTROLLER_H
#define RATE_CONTROLLER_H

#include "Controller.h"

class RateController: public Controller 
{
public:
    virtual Response post(Request* request);
private:   
    int film_id;
    int score;
    void check_post_params();
};

#endif