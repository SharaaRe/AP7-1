#ifndef FILM_FILTER_SERVICE_H
#define FILM_FILTER_SERVICE_H

#include <vector> 
#include <map>
#include <string>

#include "Film.h"

#define NOT_FILTERED_ST "not filterd"
#define NOT_FILTERED -1

class FilmFilterService
{
public:
    FilmFilterService(std::vector <Film> films);
    FilmFilterService() = default;
    void filter(std::string name = NOT_FILTERED_ST, int max_year = NOT_FILTERED, int min_year = NOT_FILTERED,
             int price = NOT_FILTERED, float min_rate = NOT_FILTERED, std::string director = NOT_FILTERED_ST);
    void stable_sort_by_rate();
    void filter_purchased(std::vector <Film> purchased);
    void filter_not_available();
    void filter_referring_film(int id);
    std::vector <Film> get_filtered();
protected:
    std::vector <Film> films;
    void filter_by_name(std::string name);
    void filter_by_max_year(int max_year);
    void filter_by_min_year(int min_year);
    void filter_by_price(int price);
    void filter_by_min_rate(float rate);
    void filter_by_director(std::string director);
    static bool compare_by_rate(Film first, Film second);
};

#endif