#include "Publisher.h"

#include "Film.h"

#include "Exceptions.h"

using namespace std;

Publisher::Publisher(string email, string username, string password, int age)
    :Client(email, username, password, age)
{}

void Publisher::add_film(Film* new_film)
{   
    published.insert(pair<int, Film*> (new_film->get_id(), new_film));
}

void Publisher:: delete_film(int film_id)
{
    if (published.find(film_id) == published.end())
        throw new PermissionDenied("film id doesn't belong to user");
    else
        published.erase(film_id);
}

bool film_is_published_by_user(int film_id)
{}


std::vector <std::string> Publisher::get_followers()
{
    return followers;
}


void Publisher:: reply_comment(int film_id, int comment_id)
{

}

