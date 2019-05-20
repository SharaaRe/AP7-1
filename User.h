#ifndef USER_H
#define USER_H


#include <string>
#include <vector>

enum UserType {ADMIN, CLIENT, PUBLISHER};


class User
{
public:
    User(std::string username, std::string password);
    bool valid_login(std::string username, std::string password);

    std::string get_username();
    int get_id();
    virtual int get_type();

protected:
    // static int type;
    int id;
    std::string email;
    std::string username;
    std::string password;
};


#endif