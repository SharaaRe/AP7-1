#include "DataBase.h"

#include <iostream>

#include "Client.h"
#include "User.h"
#include "Film.h"
#include "Exceptions.h"
#include "md5.h"



using namespace std;

DataBase* DataBase::instance = nullptr;

DataBase::DataBase()
{
    last_film_id = 0;
    last_user_id = 0;
    admins[ADMIN_ST] = new User(ADMIN_ST, md5(ADMIN_ST));
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

    for (map <int, Film*> ::iterator it = films.begin() ; it != films.end(); it++)
        delete it->second;
    
    delete this;
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

User* DataBase::search_user(std::string username)
{
    if(id.find(username) != id.end())
        return search_client(id[username]);

    else if (admins.find(username) != admins.end())
        return admins[username];
}

User* DataBase::search_user(int _id)
{
    string username = ADMIN_ST;
    if (_id != 0)
        if(clients.find(_id) != clients.end())
            return search_client(_id);

    else if (admins.find(username) != admins.end())
        return admins[username];
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
    {
        throw NotFound("film not found in data base");
    }
}



vector <Film> DataBase::get_all_films()
{
    vector <Film> res;
    for (auto it = films.begin(); it != films.end(); it++)
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
    return id.find(username) == id.end() && admins.find(username) == admins.end();
}




