#ifndef FILM_SERVICE_H
#define FILM_SERVICE_H

#include <string>
#include <vector>

#include "Client.h"
#include "Publisher.h"
#include "Film.h"

#define NAME "name"
#define FILM_ID "film_id"
#define COMMENT_ID "comment_id"
#define CONTENT "content"
#define SCORE "score"
#define NOT_CHANGED "not changed"
#define VALUE_NOT_CHANGED -1

class DataBase;
class UserSessionManagement;

typedef std::string Notification;

class FilmService
{
public:
    FilmService();
    void buy(int film_id);
    void add_film(std::string name, int year, int length, int price, std::string summary, std::string director);
    void edit_film(int id, std::string name = NOT_CHANGED, int year = VALUE_NOT_CHANGED,int length = VALUE_NOT_CHANGED,
             std::string summary = NOT_CHANGED, std::string director = NOT_CHANGED);
    void delete_(int id);
    void rate(int id, int score);
    void comment(int id, std::string content);
    void delete_comment(int film_id, int comment_id);
    void reply(int film_id, int comment_id, std::string content);
    std::vector <Film> get_purchased();
    std::vector <Film> get_published();
    std::vector <Film> get_all_films();
    std::vector <Film> get_recommendation_list(Film refferin_film);

private:
    DataBase* database;
    UserSessionManagement* user_manager;
    void check_edit_access(int id);
    void check_client_access(int film_id);
    void send_film_add_notif(std::vector <int> followers_id);
    int calculate_publisher_part(float rate, int price);
    Notification new_film_notification(Publisher publisher);
    Notification rate_notification(Client client, Film film);
    Notification buy_notification(Client client, Film film);
    Notification comment_notification(Client client, Film film);
    Notification reply_notification(Publisher publisher);

};

#endif