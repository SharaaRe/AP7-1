#include "UserService.h"

#include <sstream>

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
    user_manager = UserSessionManagement::get_instance();
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
        user_manager->set_logged_user(database->search_client(username));
    else 
        throw BadRequest("wrong password");
}

void  UserService::follow(int following_id)
{
    Client* logged_client = user_manager->get_logged_client();

    Publisher* publisher = dynamic_cast <Publisher*> (database->search_client(following_id));
    if (publisher != nullptr)
    {
        logged_client->follow(publisher);
        publisher->add_follower(logged_client->get_id());
        publisher->send_notif(follow_notification(*logged_client));
    }
    else 
        throw BadRequest("following id doesnt belong to a publisher");
}


vector <const Client*> UserService::get_followers()
{
    Publisher* publisher = user_manager->get_logged_publisher();

    vector <int> follower_ids;
    follower_ids = publisher->get_followers();

    vector <const Client*> followers;
    for (int i = 0; i < follower_ids.size(); i++)
        followers.push_back(database->search_client(follower_ids[i]));
    
    return followers;
}

vector <Notification> UserService::get_notifications(bool read)
{
    Publisher* publisehr = user_manager->get_logged_publisher();
    if (read)
        return publisehr->get_read_notification();

    return publisehr->get_notification();
}

Notification UserService::follow_notification(Client client)
{
    stringstream notif;
    notif << "User " << client.get_username() << " with id " << client.get_id() << " follow you.";
    return notif.str();
}
