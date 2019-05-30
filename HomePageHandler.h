#ifndef HOME_PAGE_HANDLER_H
#define HOME_PAGE_HANDLER_H

#include "APHTTP/server/server.hpp"
#include "FilmService.h"
#include "UserService.h"


class HomePageHandler: public TemplateHandler
{
public:
    HomePageHandler(std::string file_path);
    virtual Response* callback(Request* req);
    virtual std::map<std::string, std::string> handle(Request *req);
private:
    FilmService film_service;
    std::vector <Film> published_films;
};

#endif