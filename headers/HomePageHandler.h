#ifndef HOME_PAGE_HANDLER_H
#define HOME_PAGE_HANDLER_H

#include "server.hpp"
#include "FilmService.h"
#include "UserService.h"


class HomePageHandler: public TemplateHandler
{
public:
    HomePageHandler(std::string file_path);
    virtual Response* callback(Request* req);
    void publisher_handler(Request* req);
    void client_handler(Request* req);
    virtual std::map<std::string, std::string> handle(Request *req);
private:
    FilmService film_service;
    Response* res;
    std::vector <Film> published_films;
    std::vector <Film> films;
    bool publisher;

};

#endif