#include "UserSessionManagement.h"

#include "Exceptions.h"
#include "User.h"
#include "Publisher.h"
#include "Client.h"

UserSessionManagement* UserSessionManagement::instance = nullptr;

UserSessionManagement* UserSessionManagement::get_instance()
{
    if (instance == nullptr)
        instance = new UserSessionManagement();

    return  instance;
}

void UserSessionManagement::set_logged_user(User* _logged_user)
{
    if (logged_user != nullptr)
        throw BadRequest("some exception in case log out do exist");

    logged_user = _logged_user;
}

User* UserSessionManagement::get_logged_user()
{
    return logged_user;
}

Publisher* UserSessionManagement::get_logged_publisher()
{
    Publisher* publisher = dynamic_cast <Publisher*> (logged_user);
    if (publisher == NULL)
        throw PermissionDenied("this is not publisher type");
}

Client* UserSessionManagement::get_logged_client()
{
    Client* client = dynamic_cast <Client*> (logged_user);
    if (client == NULL)
        throw PermissionDenied("this is not client type");
}

bool UserSessionManagement::is_publisher()
{
    if (logged_user->get_type())
        return true;
    else 
        return false;
}

