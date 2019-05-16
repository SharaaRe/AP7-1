#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <string>

class Film;
class Client;
class Publisher;

class DataBase 
{
public:
    static DataBase* get_instance();
    void add_client(Client* new_client);
    void add_publisher(Publisher* new_publisher);
    void add_film(Film* new_film);

    Client* search_client(std::string username);
    Publisher* search_publisher(std::string username);
    Film* search_film(int id);
private:
    std::map <int, Film*> films;
    std::map <std::string, Client*> clients;
    std::map <std::string, Publisher*> publishers;
    // DataBase
    static DataBase* instance;

};

#endif