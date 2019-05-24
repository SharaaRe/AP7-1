#include "DataBase.h"

#include "Client.h"
#include "User.h"
#include "Film.h"
#include "Exceptions.h"

using namespace std;

DataBase* DataBase::instance = nullptr;

DataBase::DataBase()
{
    last_film_id = 0;
    last_user_id = 0;
}

DataBase* DataBase::get_instance()
{
    if (instance == nullptr)
        instance = new DataBase();
    return instance;
}

DataBase::~DataBase()
{
    for (map <int, Client*> ::iterator it = clients.begin() ; it != clients.end(); it++)
        delete it->second;
}


void DataBase::add_client(Client* new_user)
{
    if (valid_username(new_user->get_username())
            && clients.find(new_user->get_id()) == clients.end())
    {
        new_user->set_id(++last_user_id);
        clients.insert(pair <int, Client*> (new_user->get_id(), new_user));
        id.insert(pair<string, int> (new_user->get_username(), new_user->get_id()));
    }
    else 
    {
        delete new_user;
        throw BadRequest("user name and id already exist");
    }
}

void DataBase::add_film(Film* new_film)
{
    new_film->set_id(++last_film_id);
    if (films.find(new_film->get_id()) == films.end())
        films.insert(pair <int, Film*> (new_film->get_id(), new_film));
}

Client* DataBase::search_client(int id)
{
    if (clients.find(id) != clients.end())
        return clients[id];
    
    else
        throw NotFound("not found in database");
}

Client* DataBase::search_client(std::string username)
{
    if(id.find(username) != id.end())
        return search_client(id[username]);
}


Film* DataBase::search_film(int film_id)
{
    if (films.find(film_id) != films.end())
        return films[film_id];
    else 
        throw NotFound("film not found in data base");
}



vector <Film> DataBase::get_all_films()
{
    vector <Film> res;
    for (map <int, Film*>:: iterator it = films.begin(); it != films.end(); it++)
    {
        if (it->second->is_available())
            res.push_back(*(it->second));
    }

    return res;
}

bool DataBase::film_exist(int id)
{
    return films.find(id) != films.end();
}

bool DataBase::client_exist(int id)
{
    return clients.find(id) != clients.end();
}

bool DataBase::valid_username(string username)
{
    return id.find(username) == id.end();
}
//entities must add toghether or one by one



