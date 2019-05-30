#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Client.h"

#include <map>

class Film;

class Publisher: public Client
{
public:
    Publisher(std::string email, std::string username, std::string password, int age);
    void add_film(Film* film);
    void delete_film(int film_id);
    bool film_is_published_by_user(int film_id) const;
    void add_follower(int id);
    std::vector <int> get_followers() const;
    void reply_comment(int film_id, int comment_id);
    void sell_film(int publisher_part);
    int get_debt();
    void pay_debt();
    std::vector <Film> get_published();
protected:
    int debt;
    std::map <int, Film*> published;
    std::vector <int> followers;
};

#endif