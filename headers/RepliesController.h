#ifndef REPLIES_CONTROLLER_H
#define REPLIES_CONTROLLER_H

#include <string>

#include "Controller.h"


class RepliesController:public Controller
{
public: 
    virtual service::Response post(service::Request* request);
private:
    int film_id;
    int comment_id;
    std::string content;
    void check_post_params();
};

#endif
