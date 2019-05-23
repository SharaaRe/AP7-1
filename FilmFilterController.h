#ifndef FILM_FILTER_CONTROLLER_H
#define FILM_FILTER_CONTROLLER_H

#include "Controller.h"
#include "FilmService.h"
#include "FilmFilterService.h"

class FilmFilterController: public Controller
{
public:
    virtual Response get(Request* request);
protected:
    Response make_get_film_response();
    std::vector <Film> films;
    FilmService film_service;
    std::string name;
    std::string director;
    int min_year;
    int max_year;
    int price;
    float rate;
    void default_filter();
    virtual void check_params();
    void re_initialize_params();
};


#endif