#ifndef COMMENTS_CONTROLLER_H
#define COMMENTS_CONTROLLER_H

#include <string>

#include "Controller.h"

class CommentsController: public Controller
{
public:
    virtual Response post(Request* request);
    virtual Response delete_(Request* request);
private:
    int film_id;
    int comment_id;
    std::string content;
    void check_post_params();
    void check_delete_params();
};

#endif