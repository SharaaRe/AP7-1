#ifndef FILM_SERVICE_H
#define FILM_SERVICE_H

#include <string>
#include <vector>

#define NOT_CHANGED "not changed"
#define VALUE_NOT_CHANGED -1

class Publisher;
class DataBase;
class UserSessionManagement;
class Film;

class FilmService
{
public:
    FilmService();
    void add_film(std::string name, int year, int length, int price, std::string summery, std::string director);
    void edit_film(int id, std::string name = NOT_CHANGED, int year = VALUE_NOT_CHANGED,int length = VALUE_NOT_CHANGED,
             std::string summery = NOT_CHANGED, std::string director = NOT_CHANGED);
    void delete_(int id);
    void rate(int id, int score);
    void comment(int id, std::string content);
    std::vector <const Film*> get_purchased();

private:
    DataBase* database;
    UserSessionManagement* user_manager;
    void check_edit_access(int id);
    void send_film_add_notif(std::vector <int> followers_id);
    void buy_film(int film_id);
    int calculate_publisher_part(float rate, int price);
    Notification new_film_notification(Publisher publisher);
    Notification rate_notification(Client client, Film film);
    Notification buy_notification(Client client, Film film);
    Notification comment_notification(Client client, Film film);

};

#endif