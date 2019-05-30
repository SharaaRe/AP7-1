#ifndef PUT_FILMS_CONTROLLER_H
#define PUT_FILMS_CONTROLLER_H

#include "FilmController.h"

class PutFilmsController :public FilmController
{
public:
    service::Response post(service::Request*);
    service::Response get(service::Request*);
private:
    void post_params();
};


#endif