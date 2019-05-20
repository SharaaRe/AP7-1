#include "DataBase.h"

#include "Client.h"
#include "User.h"
#include "Film.h"
#include "Exceptions.h"

using namespace std;

DataBase* DataBase::instance = nullptr;

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
    if (films.find(new_film->get_id()) == films.end())
        films.insert(pair <int, Film*> (new_film->get_id(), new_film));
}

Client* DataBase::search_client(int id)
{
    if (clients.find(id) != clients.end())
        return clients[id];
    
    else
        throw new NotFound("not found in database");
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
        throw new NotFound("film not found in data base");
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



