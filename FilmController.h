#ifndef FILM_CONTROLLER_H
#define FILM_CONTROLLER_H

#include <string>

#include "Controller.h"
#include "FilmService.h"
#include "Film.h"

class FilmController :public Controller
{
    public:
        FilmController() = default;
        virtual Response get(Request* request);
        virtual Response post(Request* request);
        virtual Response put(Request* request);
        virtual Response delete_(Request* request);
    private:
        int id;
        FilmService film_service;
        std::string name;
        int year;
        int length;
        int price;
        std::string summery;
        std::string director;
        bool get_id_param_exist();
        void post_required_params();
        void put_params();
        void re_initialize();
        void set_id_param();
        std::string make_film_info_string(Film film);
        std::string make_recommendation_string(Film film);
        std::string make_comments_string(Film film);
};

#endif
