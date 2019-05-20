#ifndef FILM_SERVICE_H
#define FILM_SERVICE_H

#include <string>

class FilmService
{
public:
    void add_film(std::string name, int year, int length, int price, std::string summery, std::string director);
}

#endif