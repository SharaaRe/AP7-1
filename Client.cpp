#include "Client.h"
#include <iostream>

#include "Exceptions.h"

#include "Publisher.h"
#include "Film.h"

using namespace std;

int Client::last_id_created = 0;

Client::Client(string _email, string _username, string _password, int _age)
    :User(_username, _password), email(_email), age(_age)
{
    last_id_created++;
    id = last_id_created;
}


void Client::follow(Publisher* following)
{
    if (followings.find(following->get_id()) == followings.end())
        followings.insert(pair <int, const Publisher*> (following->get_id(), following));
    else 
        throw BadRequest("this publisher is already followed");
}

void Client::increase_credit(int amount)
{
    credit += amount;
}

void Client::purchase_film(Film* film)
{
    if (credit < film->get_price());
        // throw some exception
    if (purchased.find(film->get_id()) != purchased.end())
        throw BadRequest("film is already purchased");
    credit -= film->get_price();
    purchased.insert(pair <int, Film*> (film->get_id(), film));

}

int Client::get_type()
{
    return CLIENT;
}


