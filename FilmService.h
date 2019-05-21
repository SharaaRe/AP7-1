#ifndef FILM_SERVICE_H
#define FILM_SERVICE_H

#include <string>

#define NOT_CHANGED "not changed"
#define VALUE_NOT_CHANGED -1

class Publisher;

class FilmService
{
public:
    void add_film(std::string name, int year, int length, int price, std::string summery, std::string director);
    void edit_film(int id, std::string name = NOT_CHANGED, int year = VALUE_NOT_CHANGED,int length = VALUE_NOT_CHANGED,
             std::string summery = NOT_CHANGED, std::string director = NOT_CHANGED);
    void delete_(int id);
private:
    Publisher* publisher_user();
    void check_edit_access(int id);
    void send_film_add_notif(std::vector <int> followers_id);
};

#endif