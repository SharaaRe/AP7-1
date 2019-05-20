#ifndef UT_FLIX_H
#define UT_FLIX_H

#include <string>

class DataBase;
class Controller;
class RequestReciever;

class UtFlix 
{
public:
    UtFlix* get_instance();
    ~UtFlix();
private:
    UtFlix();
    static UtFlix* instance;
    DataBase* database;
    RequsetReciever* interface;
    Controller* controler;
    std::string logged_in_username;

};


#endif