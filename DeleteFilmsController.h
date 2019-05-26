#ifndef DELETE_FILMS_CONTROLLER_H
#define DELETE_FILMS_CONTROLLER_H

#include "FilmController.h"

class DeleteFilmsController :public FilmController
{
public:
    Response post(Request*);
    Response get(Request*);
};


#endif