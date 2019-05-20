#include "FilmService.h"

#include "DataBase.h"
#include "Film.h"

using namespace std;

void FilmService::add_film(string name, int year, int length, int price, string summery, string director)
{
    DataBase::get_instance()->add_film(new Film(name, year, length, price, summery, director));
}