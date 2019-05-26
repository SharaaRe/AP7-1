#include "UTflix.h"


UTflix* UTflix::instance = NULL;

UTflix* UTflix::get_instance()
{
    if (instance == NULL)
        instance = new UTflix();
    return instance;
}

void UTflix::pay_publisher_debt(Publisher* publisher)
{
    credit -= publisher->get_debt();
    publisher->pay_debt();
}

void UTflix::add_credit(int amount)
{
    credit += amount;
}

int UTflix::get_credit()
{
    return credit;
}
