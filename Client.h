#ifndef CLIENT_H
#define CLIENT_H


#include <string>
#include <vector>

class Film;
class Publisher;
class Notification;
class Comment;


class Client 
{
public:
    Client(std::string email, std::string username, std::string password, int age);
    void follow(int following_id);
    void increase_credit(int amount);
    void purchase_film(int film_id, int price);
    // void add_comment(Comment* new_comment);
    virtual void add_film(Film*);
    virtual void delete_film(int film_id);
    virtual bool film_is_published_by_user(int film_id);
    virtual std::vector <std::string> get_followers();
    virtual void reply_comment(int film_id, int comment_id);
protected:
    static int last_id_created;
    int id;
    std::string email;
    std::string username;
    std::string password;
    int age;
    int credit;
    std::vector <int> purchased;
    std::vector <int> followings;
    std::vector <Notification*> notifications;


};


#endif