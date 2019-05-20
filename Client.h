#ifndef CLIENT_H
#define CLIENT_H


#include <string>
#include <vector>
#include <map>

#include "User.h"

class Film;
class Publisher;
class Notification;
class Comment;

class Client :public User
{
public:
    Client(std::string email, std::string username, std::string password, int age);

    void follow(Publisher* follwing);
    void increase_credit(int amount);
    void purchase_film(Film* film);
    bool is_purchased(int film_id);
    virtual int get_type();

protected:
    static int last_id_created;
    std::string email;
    int age;
    int credit;
    std::map <int, Film*> purchased;
    std::map <int, const Publisher*> followings;
    std::vector <Notification*> notifications;


};


#endif