#include "Client.h"

#include "Exceptions.h"

int Client::last_id_created = 0;

Client::Client(std::string _email, std::string _username, std::string _password, int _age)
    :email(_email), username(_username), password(_password), age(_age)
{
    last_id_created++;
    id = last_id_created;
}


void Client::follow(int following_id)
{
    followings.push_back(following_id);
}

void Client::increase_credit(int amount)
{
    credit += amount;
}

void Client::purchase_film(int film_id, int price)
{
    if (credit < price);
        // throw some exception
    credit -= price;
    purchased.push_back(film_id);
}


void Client::add_film(Film* new_film)
{
    throw new PermissionDenied("non publisher client cant add a film");
}

// void reply_comment(int film_id, int comment_id)
// {
//     throw new PermissionDenied("non publisher client cant reply to comments");
// }

bool film_is_published_by_user(int film_id)
{
    throw new PermissionDenied("non publisher clients have not published any films");
}

std::vector <std::string> get_followers()
{
    throw new PermissionDenied("non publisher clients dont have followers");
}


