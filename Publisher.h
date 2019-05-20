#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Client.h"

#include <map>

class Film;

class Publisher: public Client
{
public:
    Publisher(std::string email, std::string username, std::string password, int age);
    virtual void add_film(Film* film);
    virtual void delete_film(int film_id);
    virtual bool film_is_published_by_user(int film_id) const;
    virtual std::vector <int> get_followers() const;
    virtual void reply_comment(int film_id, int comment_id);
protected:
    std::map <int, Film*> published;
    std::vector <int> followers; //keep users ids;
};

#endif