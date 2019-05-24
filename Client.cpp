#include "Client.h"
#include <iostream>

#include "Exceptions.h"

#include "Publisher.h"
#include "Film.h"

#define NOT_ASSIGNED -1

using namespace std;

int Client::last_id_created = 0;

Client::Client(string _email, string _username, string _password, int _age)
    :User(_username, _password), email(_email), age(_age)
{   
    credit = 0;
    id = ++last_id_created;
    // id = NOT_ASSIGNED;
}

void Client::set_id(int _id)
{
    if (id == NOT_ASSIGNED)
        id = _id;
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
    if (credit < film->get_price())
        throw PermissionDenied("not enough money");
    if (purchased.find(film->get_id()) != purchased.end())
        throw BadRequest("film is already purchased");

    credit -= film->get_price();
    purchased.insert(pair <int, Film*> (film->get_id(), film));
}

void Client::send_notif(Notification new_notif)
{
    notifications.push_back(new_notif);
}

bool Client::is_purchased(int film_id) const
{
    if (purchased.find(film_id) == purchased.end())
        return false;
    else
        return true;
    
}


int Client::get_type() const
{
    return CLIENT;
}



std::string Client::get_email() const
{
    return email;
}


vector <Notification> Client::get_notification()
{
    vector <Notification> res = notifications;
    for (int i = 0; i < notifications.size(); i++)
    {
        read_notification.push_back(notifications[i]);
    }
    notifications.clear();
    return res;
}


vector <Notification> Client::get_read_notification()
{
    return read_notification;
}

vector <int> Client::get_purchased()
{
    vector <int> res;
    for (map <int, Film*>::iterator it = purchased.begin(); it != purchased.end(); it++)
    {
        res.push_back(it->first);
    }

    return res;
}


