#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <string>

class Film;
class Client;
class Publisher;
class User;

class DataBase 
{
public:
    static DataBase* get_instance();
    void add_client(Client* new_client);
    // void add_publisher(Publisher* new_publisher);
    void add_film(Film* new_film);

    Client* search_client(int id);
    Client* search_client(std::string username);
    Publisher* search_publisher(int id);
    Film* search_film(int id);

    bool film_exist(int id);
    bool publisher_exist(int id);
    bool client_exist(int id);
    bool valid_username(std::string username);

    ~DataBase();
private:
    std::map <int, Film*> films;
    std::map <int, Client*> clients;
    // std::map <int, Publisher*> publishers;
    std::map <std::string, User*> admins;
    std::map <std::string, int> id;
    // DataBase
    static DataBase* instance;

};

#endif