#include "User.h"

using namespace std;


User::User(string _username, string _password)
    :username(_username), password(_password)
{}

bool User::valid_login(string _username, string _password)
{
    return (username == _username && password == _password);
}

int User::get_id()
{
    return id;
}

std::string User::get_username()
{
    return username;
}

int User::get_type()
{
    return ADMIN;
}
