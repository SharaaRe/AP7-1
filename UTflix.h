#ifndef UT_FLIX_H
#define UT_FLIX_H

#include <string>

#include "Publisher.h"

class DataBase;
class Controller;
class RequestReciever;


class UTflix 
{
public:
    static UTflix* get_instance();
    void pay_publisher_debt(Publisher* publisher);
    void add_credit(int amount);
    ~UTflix();
private:
    UTflix();
    static UTflix* instance;
    int credit;

};


#endif