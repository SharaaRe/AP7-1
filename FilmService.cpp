#include "FilmService.h"

#include "DataBase.h"
#include "UserSessionManagement.h"
#include "Publisher.h"
#include "Film.h"
#include "Exceptions.h"

using namespace std;

void FilmService::add_film(string name, int year, int length, int price, string summery, string director)
{
    Publisher* publisher = dynamic_cast <Publisher*> (UserSessionManagement::get_instance()->get_logged_user());
    if (publisher == NULL)
        throw PermissionDenied("this user doesnt access to add films");
    Film* new_film = new Film(name, year, length, price, summery, director);
    DataBase::get_instance()->add_film(new_film);
    publisher->add_film(new_film);
}