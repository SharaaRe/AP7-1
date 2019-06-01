#ifndef DELETE_FILMS_HANDLER_H
#define DELETE_FILMS_HANDLER_H

#include "server.hpp"


class DeleteFilmsHandler: public RequestHandler
{
public:
    Response* callback(Request*);
};


#endif