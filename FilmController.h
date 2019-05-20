#ifndef FILM_CONTROLLER_H
#define FILM_CONTROLLER_H

#include <string>

#include "Controller.h"
#include "FilmService.h";

class FilmController :public Controller
{
    public:
        FilmController();
        virtual Response post(Request* request);
    private:
        FilmService film_service;
        std::string name;
        int year;
        int length;
        int price;
        std::string summery;
        std::string director;
        void post_required_params();
        void re_initialize();
};

#endif
