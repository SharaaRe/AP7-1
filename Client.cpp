#include "Client.h"


Client::Client(std::string _email, std::string _username, std::string _password, int _age, int _id)
    :email(_email), username(_username), password(_password), age(_age), id(_id)
{}


void Client::follow(int following_id)
{
    followings.push_back(following_id);
}


void Client::purchase_film(int film_id, int price)
{
    if (credit < price);
        // throw some exception
    credit -= price;
    purchased.push_back(film_id);
}

