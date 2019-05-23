#include "FilmService.h"

#include <string>
#include <sstream>

#include "DataBase.h"
#include "UserSessionManagement.h"
#include "Publisher.h"
#include "Film.h"
#include "Exceptions.h"
#include "UTflix.h"

enum {WEAK = 80, MEDIUM = 90, HIGH = 95};

#define WEAK_BORDER 5.0
#define HIGH_BORDER 8.0

#define USER_ST "User "
#define PUBLISHER_ST "Publisher "
#define WITH_ID " with id "

using namespace std;


FilmService::FilmService()
{
    user_manager = UserSessionManagement::get_instance();
    database = DataBase::get_instance();
}

void FilmService::buy(int film_id)
{
    Client* client = UserSessionManagement::get_instance()->get_logged_client();
    Film* film = DataBase::get_instance()->search_film(film_id);
    Publisher* publisher = dynamic_cast <Publisher*> (DataBase::get_instance()->search_client(film->get_publisher_id()));
    if (film->is_available())
    {
        client->purchase_film(film);
        publisher->sell_film(calculate_publisher_part(film->get_rate(), film->get_price()));
    }
    else
        throw NotFound("film is not available");
}

void FilmService::add_film(string name, int year, int length, int price, string summery, string director)
{
    Publisher* publisher = user_manager->get_logged_publisher();
    Film* new_film = new Film(name, year, length, price, summery, director, publisher->get_id());
    database->add_film(new_film);
    publisher->add_film(new_film);
    send_film_add_notif(publisher->get_followers());
}

void FilmService::edit_film(int id, string _name, int _year,int _length, string _summery, string _director)
{
    string name, summery, director;
    int  length, year;
    Film* film = database->search_film(id);
    check_edit_access(id);

    if (name != NOT_CHANGED)
        film->set_name(name);
    if (summery != NOT_CHANGED)
        film->set_summery(summery);
    if (director != NOT_CHANGED)
        film->set_director(director);
    if (year != VALUE_NOT_CHANGED)
        film->set_year(year); 
    if (length != VALUE_NOT_CHANGED)
        film->set_length(length);   
}

void FilmService::delete_(int id)
{
    Film* film = database->search_film(id);
    check_edit_access(id);
    film->delete_();
}

void FilmService::rate(int id, int score)
{
    Film* film = database->search_film(id);
    Client* client = user_manager->get_logged_client();
    check_client_access(id);
    
    film->add_score(score);
    Client*  publisher = database->search_client(film->get_publisher_id());
    publisher->send_notif(rate_notification(*client, *film));

}

void FilmService::comment(int id, std::string content)
{
    Film* film = database->search_film(id);
    Client* client = user_manager->get_logged_client();
    check_client_access(id);

    film->add_comment(content, client->get_id());
    Client*  publisher = database->search_client(film->get_publisher_id());
    publisher->send_notif(comment_notification(*client, *film));
}

void FilmService::delete_comment(int film_id, int comment_id)
{
    Film* film = database->search_film(film_id);
    check_edit_access(film_id);
    film->delete_comment(comment_id);
}

void FilmService::reply(int film_id, int comment_id, std::string content)
{
    Film* film = database->search_film(film_id);
    Publisher* publisher = dynamic_cast <Publisher*> (database->search_client(film->get_publisher_id()));
    check_edit_access(film_id);
    film->reply_comment(comment_id, content);

    Client* commenter = database->search_client(film->get_commenter_id(comment_id));
    commenter->send_notif(reply_notification(*publisher));
}


void FilmService::check_edit_access(int id)
{
    Publisher* publisher = user_manager->get_logged_publisher();
    if (!publisher->film_is_published_by_user(id))
        throw PermissionDenied("this film doesn't belong to this user");
    
}

void FilmService::check_client_access(int film_id)
{
    Client* client = user_manager->get_logged_client();
    if (!client->is_purchased(film_id))
        throw PermissionDenied("this client didn't buy this film");
}

void FilmService::send_film_add_notif(vector <int> followers_id)
{
    string notif;
    Publisher* publisher_user = user_manager->get_logged_publisher();
    notif = new_film_notification(*publisher_user);
    for (int i = 0; i < followers_id.size(); i++)
    {
        Client* follower = database->search_client(followers_id[i]);
        follower->send_notif(notif);
    }

}

void FilmService::buy_film(int film_id)
{
    Client* client = user_manager->get_logged_client();
    Film* film = database->search_film(film_id);
    int publisher_id = film->get_publisher_id();
    Publisher* publisher = dynamic_cast <Publisher*> (database->search_client(publisher_id));

    if (film->is_available())
    {
        client->purchase_film(film);
        int publisher_share = calculate_publisher_part(film->get_rate(), film->get_price());
        publisher->sell_film(publisher_share);
        publisher->send_notif(buy_notification(*client, *film));
    }
    else
        throw NotFound("film is not available");
}



int FilmService::calculate_publisher_part(float rate, int price)
{
    if (rate < WEAK_BORDER)
        return price * WEAK / 100;
    
    if (rate >= WEAK_BORDER && rate < HIGH_BORDER)
        return price * MEDIUM / 100;

    if (rate >= HIGH_BORDER)
        return price * HIGH / 100;

}

Notification FilmService::new_film_notification(Publisher publisher)
{
    stringstream notif;
    notif << PUBLISHER << publisher.get_username() << WITH_ID  
             << publisher.get_id() << "register new film.";
    return notif.str();
}

Notification FilmService::rate_notification(Client client, Film film)
{
    stringstream notif;
    notif << USER_ST << client.get_username() << WITH_ID << client.get_id() 
            << " rate on your film " << WITH_ID << film.get_id() << ".";
    return notif.str();
}

Notification FilmService::comment_notification(Client client, Film film)
{
    stringstream notif;
    notif << USER_ST << client.get_username() << WITH_ID << client.get_id() 
            << " comment on your film " << WITH_ID << film.get_id() << ".";
    return notif.str();
}

Notification FilmService::buy_notification(Client client, Film film)
{
    stringstream notif;
    notif << USER_ST << client.get_username() << WITH_ID << client.get_id() 
            << " buy your film " << WITH_ID << film.get_id() << ".";
    return notif.str();
}


Notification FilmService::reply_notification(Publisher publisher)
{
    stringstream notif;
    notif << PUBLISHER_ST << publisher.get_username() << WITH_ID << publisher.get_id()
            << "reply to you comment.";

    return notif.str();
}
