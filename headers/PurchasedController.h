#ifndef PURCHASED_CONTROLLER_H
#define PURCHASED_CONTROLLER_H

#include "FilmFilterController.h"


class PurchasedController :public FilmFilterController
{
public:
    virtual service::Response get(service::Request* request);
private: 
    int nothing;
};

#endif