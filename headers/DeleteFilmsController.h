#ifndef DELETE_FILMS_CONTROLLER_H
#define DELETE_FILMS_CONTROLLER_H

#include "FilmController.h"

class DeleteFilmsController :public FilmController
{
public:
    service::Response post(service::Request*);
    service::Response get(service::Request*);
};


#endif