#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <vector>

#define USERNAME "username"
#define PASSWORD "password"
#define EMAIL "email"
#define AGE "age"
#define PUBLISHER_PARAM "publisher"

#include "Request.h"

class Response;
class DataBase;
class Client;

class   UserService
{
public:
    UserService();
    void signup(std::string email, std::string username, std::string password, int age, bool publisher);
    void login(std::string username, std::string password);
    void follow(int publisher_id);
    std::vector <const Client*> get_followers();
private:
    DataBase* database;

};

#endif