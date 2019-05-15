#ifndef CLIENT_H
#define CLIENT_H


#include <string>
#include <vector>

class Film;
class Publisher;
class Notification;


class Client 
{
public:
    Client(std::string email, std::string username, std::string password, int age, int id);
    void follow(int following_id);
    void increase_credit(int amount);
    void purchase_film(int film_id, int price);
protected:
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