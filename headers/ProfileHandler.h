#ifndef PROFILE_HANDLER_H
#define PROFILE_HANDLER_H

#include "server.hpp"
#include "Film.h"

class ProfileHandler: public TemplateHandler
{
public:
    ProfileHandler(std::string);
    Response* callback(Request*);
    virtual std::map <std::string, std::string> handle(Request* req);
private:
    std::vector <Film> purchased_films;
};

#endif