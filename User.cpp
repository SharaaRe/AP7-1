#include "User.h"


using namespace std;

#include "UTflix.h"

User::User(string _username, string _password)
    :username(_username), password(_password)
{}

bool User::valid_login(string _username, string _password)
{
    return (username == _username && password == _password);
}

int User::get_id() const
{
    return id;
}

std::string User::get_username() const
{
    return username;
}

int User::get_type() const
{
    return ADMIN;
}

int User::get_money() const
{
    return UTflix::get_instance()->get_credit();
}