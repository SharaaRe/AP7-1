#include "UserService.h"

#include "Response.h"
#include "Request.h"
#include "DataBase.h"
#include "Client.h"
#include "Publisher.h"
#include "md5.h"
#include "Exceptions.h"
#include "UserSessionManagement.h"

using namespace std;

UserService::UserService()
{
    database = DataBase::get_instance();
}

void UserService::signup(std::string email, std::string username, std::string password, int age, bool publisher)
{
    Client* new_client;
    if (publisher)
        new_client = new Publisher(email,username, password, age);
    else
        new_client = new Client(email,username, password, age);

    database->add_client(new_client);
    login(username, password);
}

void UserService::login(string username, string password)
{
    if (database->search_client(username)->valid_login(username, password))
        UserSessionManagement::get_instance()->set_logged_user(database->search_client(username));
    else 
        throw new BadRequest("wrong password");
}

void  UserService::follow(int following_id)
{
    User* logged_user = UserSessionManagement::get_instance()->get_logged_user();

    Publisher* publisher = dynamic_cast <Publisher*> (database->search_client(following_id));
    if (publisher != nullptr)
    {
        Client* logged_client = dynamic_cast <Client*> (logged_user);
        if (logged_client != nullptr)
            logged_client->follow(publisher);
        else 
            throw PermissionDenied("logged user is not a client");
    }
    throw BadRequest("following id doesnt belong to a publisher");
}

vector <const Client*> UserService::get_followers()
{
    Publisher* publisher = dynamic_cast<Publisher*>(UserSessionManagement::get_instance()->get_logged_user());
    vector <int> follower_ids;
    if (publisher != nullptr)
        follower_ids = publisher->get_followers();
    else 
        throw PermissionDenied("this user can't have followers");
    
    vector <const Client*> followers;
    for (int i = 0; i < follower_ids.size(); i++)
        followers.push_back(database->search_client(follower_ids[i]));
    
    return followers;
}
