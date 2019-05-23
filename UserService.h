#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <vector>

#define USER_ID "user_id"
#define USERNAME "username"
#define PASSWORD "password"
#define EMAIL "email"
#define AGE "age"
#define PUBLISHER_PARAM "publisher"

#include "Request.h"

class Response;
class DataBase;
class UserSessionManagement;
class Client;

typedef std::string Notification;

class UserService
{
public:
    UserService();
    void signup(std::string email, std::string username, std::string password, int age, bool publisher);
    void login(std::string username, std::string password);
    void follow(int publisher_id);
    std::vector <const Client*> get_followers();
    std::vector <Notification> get_notifications();
private:
    DataBase* database;
    UserSessionManagement* user_manager;
    Notification follow_notification(Client follower);
    

};

#endif