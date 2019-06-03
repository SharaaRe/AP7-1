#ifndef FILM_DETAIL_HANDLER_H
#define FILM_DETAIL_HANDLER_H

#include "server.hpp"
#include "Film.h"
#include "Comment.h"

class FilmDetailHandler: public TemplateHandler
{
public:
    FilmDetailHandler(std::string file_path);
    std::map <std::string, std::string> handle(Request*);
    Response* callback(Request*);
private:
    void handle_msg();
    void handle_error();
    int film_id;
    bool access;
    bool available;
    std::vector <Comment> comments;
    Film film;
    std::vector <Film> recoms;
    std::string msg;
    std::string error;
};


#endif 