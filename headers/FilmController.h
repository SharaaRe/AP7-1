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
        virtual service::Response get(service::Request* request);
        virtual service::Response post(service::Request* request);
    protected:
        int id;
        FilmService film_service;
        std::string name;
        int year;
        int length;
        int price;
        std::string summary;
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