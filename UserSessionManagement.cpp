#include "UserSessionManagement.h"

#include "Exceptions.h"
#include "DataBase.h"
#include "User.h"
#include "Publisher.h"
#include "Client.h"

UserSessionManagement* UserSessionManagement::instance = nullptr;

UserSessionManagement::UserSessionManagement()
{
    logged_user = nullptr;
}

UserSessionManagement* UserSessionManagement::get_instance()
{
    if (instance == nullptr)
        instance = new UserSessionManagement();

    return  instance;
}

void UserSessionManagement::set_logged_user(User* _logged_user)
{
    if (logged_user != nullptr)
        throw BadRequest("a user is already logged");
    else
        logged_user = _logged_user;
}


void UserSessionManagement::set_logged_user(int id)
{
    if (logged_user != nullptr)
        throw BadRequest("a user is already logged");

    logged_user = DataBase::get_instance()->search_user(id);
}

int UserSessionManagement::get_session_id()
{
    return logged_user->get_id();
}

void UserSessionManagement::sign_out()
{
    if (logged_user == nullptr)
        throw BadRequest("No user is logged in");

    logged_user = nullptr;    
}

User* UserSessionManagement::get_logged_user()
{
    if (logged_user == nullptr)
        throw BadRequest("please log in first");
    return logged_user;
}

Publisher* UserSessionManagement::get_logged_publisher()
{
    Publisher* publisher = dynamic_cast <Publisher*> (get_logged_user());
    if (publisher == NULL)
        throw PermissionDenied("this is not publisher type");
}

Client* UserSessionManagement::get_logged_client()
{
    Client* client = dynamic_cast <Client*> (get_logged_user());
    if (client == NULL)
        throw PermissionDenied("this is not client type");
}

bool UserSessionManagement::is_logged_in()
{
    if (logged_user == nullptr)
        return false;
    else
        return true;
}


