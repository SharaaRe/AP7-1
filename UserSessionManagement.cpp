#include "UserSessionManagement.h"

#include "User.h"

UserSessionManagement* UserSessionManagement::instance = nullptr;

UserSessionManagement* UserSessionManagement::get_instance()
{
    if (instance == nullptr)
        instance = new UserSessionManagement();

    return  instance;
}

void UserSessionManagement::set_logged_user(User* _logged_user)
{
    // if (logged_user != nullptr)
    //     throw "some exception in case log out do exist";

    logged_user = _logged_user;
}

User* UserSessionManagement::get_logged_user()
{
    return logged_user;
}

bool UserSessionManagement::is_publisher()
{
    if (logged_user->get_type())
        return true;
    else 
        return false;
}

