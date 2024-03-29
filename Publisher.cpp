#include "Publisher.h"

#include "Film.h"
#include "Exceptions.h"
#include "DataBase.h"

using namespace std;

Publisher::Publisher(string email, string username, string password, int age)
    :Client(email, username, password, age)
{
    debt = 0;
}


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

bool Publisher::film_is_published_by_user(int film_id) const
{
    if (published.find(film_id) == published.end())
        return false;
    else
        return true;
}

void Publisher::add_follower(int id)
{
    followers.push_back(id);
}


std::vector <int> Publisher::get_followers() const
{
    return followers;
}


void Publisher:: reply_comment(int film_id, int comment_id)
{
    Film* film = DataBase::get_instance()->search_film(film_id);
    if (film_is_published_by_user(film_id));
        // if comment do exist or something
}

void Publisher::sell_film(int publisher_part)
{
    debt += publisher_part;
}

int Publisher::get_debt()
{
    return debt;
}

void Publisher::pay_debt()
{
    credit += debt;
    debt = 0;
}

vector <Film> Publisher::get_published()
{
    vector <Film> res;
    for (map <int, Film*>::iterator it = published.begin(); it != published.end(); it++)
    {
        res.push_back(*(it->second));
    }

    return res;
}

