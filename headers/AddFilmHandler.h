#ifndef ADD_FILM_HANDLER_H
#define ADD_FILM_HANDLER_H

#include "server.hpp"
#include "FilmService.h"
#include "UserService.h"

class AddFilmHandler: public RequestHandler
{
public:
    virtual Response* callback(Request*);
private:
    std::string name;
    std::string director;
    std::string summary;
    std::string year;
    std::string price;
    std::string length;
};

#endif