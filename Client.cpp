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

// vector <const Film*> Client::get_purchased()
// {
//     return purchase_film
// }


