#ifndef DELETE_COMMENTS_CONTROLLER_H
#define DELETE_COMMENTS_CONTROLLER_H

#include "CommentsController.h"

class DeleteCommentsController: public CommentsController
{
public:
    Response post(Request*);
};

#endif