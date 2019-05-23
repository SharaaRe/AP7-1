#ifndef BUY_CONTROLLER_H
#define BUY_CONTROLLER_H

#include "Controller.h"

class BuyController : public Controller
{
public:
    virtual Response post(Request* request);
private:
    int film_id;
    void check_post_params();
    int calculate_publisher_debt(int price, float rate);

};


#endif