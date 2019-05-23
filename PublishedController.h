#ifndef PUBLISHED_CONTROLLER_H
#define PUBLISHED_CONTROLLER_H

#include "FilmFilterController.h"

class PublishedController: public FilmFilterController
{
public:
    virtual Response get(Request* request);
protected:
    virtual void check_params();
};

#endif