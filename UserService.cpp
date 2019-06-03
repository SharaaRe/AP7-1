#include "UserService.h"

#include <sstream>
#include <iostream>

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
    if (!database->valid_username(username))
        throw BadRequest("Username alredy exist");
    
    if (user_manager->is_logged_in())
        throw BadRequest("a user is already signed in");
    Client* new_client;
    if (publisher)
        new_client = new Publisher(email, username, md5(password), age);
    else
        new_client = new Client(email,username, password, age);
    database->add_client(new_client);
    user_manager->login(new_client->get_id());
}

void UserService::login(string username, string password)
{
    if (database->search_user(username)->valid_login(username, md5(password)))
    {
        int id = database->search_user(username)->get_id();
        user_manager->login(id);
    }
    else 
    {
        throw BadRequest("wrong password");
    }
}


void UserService::logout()
{
    user_manager->sign_out();
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

void UserService::post_money(int amount)
{
    Client* logged_client = user_manager->get_logged_client();
    logged_client->increase_credit(amount);
}

int UserService::get_session_id()
{
    return user_manager->get_logged_user()->get_id();
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
    Client* publisehr = user_manager->get_logged_client();
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
