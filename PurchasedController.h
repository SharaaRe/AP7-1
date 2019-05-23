#ifndef PURCHASED_CONTROLLER_H
#define PURCHASED_CONTROLLER_H

#include "FilmFilterController.h"
#include "Response.h"
#include "Request.h"

class PurchasedController :public FilmFilterController
{
public:
    virtual Response get(Request* request);
private: 
    int nothing;
};

#endif