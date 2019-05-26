#ifndef PUT_FILMS_CONTROLLER_H
#define PUT_FILMS_CONTROLLER_H

#include "FilmController.h"

class PutFilmsController :public FilmController
{
public:
    Response post(Request*);
    Response get(Request*);
private:
    void post_params();
};


#endif