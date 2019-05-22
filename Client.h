#ifndef CLIENT_H
#define CLIENT_H


#include <string>
#include <vector>
#include <map>

#include "User.h"



class Film;
class Publisher;
class Comment;

typedef std::string Notification;

class Client :public User
{
public:
    Client(std::string email, std::string username, std::string password, int age);

    void follow(Publisher* follwing);
    void increase_credit(int amount);
    void purchase_film(Film* film);
    void send_notif(Notification new_notif);

    bool is_purchased(int film_id) const;
    virtual int get_type() const;
    std::string get_email() const;
    std::vector <Notification> get_notification();
    std::vector <Notification> get_read_notification();
    std::vector <int> get_purchased();

protected:
    static int last_id_created;
    std::string email;
    int age;
    int credit;
    std::map <int, Film*> purchased;
    std::map <int, const Publisher*> followings;
    std::vector <Notification> notifications;
    std::vector <Notification> read_notification;


};


#endif