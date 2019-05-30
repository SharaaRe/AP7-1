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

    std::string get_username() const;
    int get_id() const;
    virtual int get_type() const;
    virtual int get_money() const;
protected:
    // static int type;
    int id;
    std::string email;
    std::string username;
    std::string password;
};


#endif