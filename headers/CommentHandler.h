#ifndef COMMENT_HANDLER_H
#define COMMENT_HANDLER_H

#include "server.hpp"

class CommentHandler:public RequestHandler
{
public:
    virtual Response* callback(Request*);
};

#endif