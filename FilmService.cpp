#include "FilmService.h"

#include <string>

#include "DataBase.h"
#include "UserSessionManagement.h"
#include "Publisher.h"
#include "Film.h"
#include "Exceptions.h"

using namespace std;

void FilmService::add_film(string name, int year, int length, int price, string summery, string director)
{
    Publisher* publisher = publisher_user();
    Film* new_film = new Film(name, year, length, price, summery, director);
    DataBase::get_instance()->add_film(new_film);
    publisher->add_film(new_film);
}

void FilmService::edit_film(int id, string _name, int _year,int _length, string _summery, string _director)
{
    string name, summery, director;
    int  length, year;
    Film* film = DataBase::get_instance()->search_film(id);
    check_edit_access(id);

    if (name != NOT_CHANGED)
        film->set_name(name);
    if (summery != NOT_CHANGED)
        film->set_summery(summery);
    if (director != NOT_CHANGED)
        film->set_director(director);
    if (year != VALUE_NOT_CHANGED)
        film->set_year(year); 
    if (length != VALUE_NOT_CHANGED)
        film->set_length(length);   
}

void FilmService::delete_(int id)
{
    Film* film = DataBase::get_instance()->search_film(id);
    check_edit_access(id);
    film->delete_();
}
// void FilmService::

Publisher* FilmService::publisher_user()
{
    Publisher* publisher = dynamic_cast <Publisher*> (UserSessionManagement::get_instance()->get_logged_user());
    if (publisher == NULL)
        throw PermissionDenied("this user doesnt access to edit films");
    return publisher;
}



void FilmService::check_edit_access(int id)
{
    Publisher* publisher = publisher_user();
    if (!publisher->film_is_published_by_user(id))
        throw PermissionDenied("this film doesn't belong to this user");
    
}