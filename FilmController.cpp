#include "FilmController.h"

#include <string>
#include <sstream>

#include <iostream>

#include "FilmService.h"
#include "FilmFilterController.h"
#include "Utils.h"
#include "Response.h"
#include "Exceptions.h"
#include "Comment.h"
#include "DataBase.h"
#include "UserSessionManagement.h"

#define FILM_ID "film_id"
#define NAME "name"
#define YEAR "year"
#define LENGTH "length"
#define PRICE "price"
#define SUMMERY "summary"
#define DIRECTOR "director"

using namespace std;
using service::Request;
using service::Response;

service::Response FilmController::get(service::Request* request)
{
    re_initialize();
    current_request = request;
    if (get_id_param_exist())
    {
        Film film = *DataBase::get_instance()->search_film(id);
        if (!film.is_available())
            throw NotFound("film is deleted");
        string film_info = make_film_info_string(film);
        string comments_info = make_comments_string(film);
        string recoms_info = make_recommendation_string(film);
        return service::Response(SUCCESSFUL, film_info + comments_info + recoms_info);
    }
    else
    {   
        FilmFilterController film_filter_controller;
        return film_filter_controller.get(request); 
    }

}

service::Response FilmController::post(service::Request* request)
{
    re_initialize();
    current_request = request;
    post_required_params();
    film_service.add_film(name, year, length, price, summary, director);

    return service::Response(SUCCESSFUL, OK);

}



void FilmController::post_required_params()
{
    try
    {
        name = current_request->get_request_param(NAME);
        string year_string = current_request->get_request_param(YEAR);
        string length_string = current_request->get_request_param(LENGTH);
        string price_string = current_request->get_request_param(PRICE);
        summary = current_request->get_request_param(SUMMERY);
        director = current_request->get_request_param(DIRECTOR);

        if (Utils::is_valid_number(year_string) && Utils::is_valid_number(length_string)
                && Utils::is_valid_number(price_string))
            
        {
            year = stoi(year_string);
            length = stoi(length_string);
            price = stoi(price_string);
            if (year < 0 && length < 0 && price < 0)
                throw BadRequest("numbers are not valid");
        }
        else 
            throw BadRequest("numbers are not a number");   
    }
    catch(NotFound& e)
    {
        throw BadRequest("params doesn't exist");
    }
    

}


void FilmController::put_params()
{
    re_initialize();

    string year_string, length_string;

    set_id_param();
    try{name = current_request->get_request_param(NAME);}
    catch(NotFound) {}

    try{summary = current_request->get_request_param(SUMMERY);}
    catch(NotFound) {}

    try{director = current_request->get_request_param(DIRECTOR);}
    catch(NotFound) {}    

    try{
        year_string = current_request->get_request_param(YEAR);
        year = Utils::string_integer_value(year_string);
    }
    catch(NotFound) {}

    try{
        length_string = current_request->get_request_param(LENGTH);
        length = Utils::string_integer_value(length_string);
    }
    catch(NotFound) {}
}


bool FilmController::get_id_param_exist()
{
    try{
        id = Utils::string_integer_value(current_request->get_request_param(FILM_ID));
        return true;
    }
    catch(NotFound& er)
    {
        return false;
    }
}



void FilmController::re_initialize()
{
    name = NOT_CHANGED;
    year = VALUE_NOT_CHANGED;
    length = VALUE_NOT_CHANGED;
    price = VALUE_NOT_CHANGED;
    summary = NOT_CHANGED;
    director = NOT_CHANGED;
}

void FilmController::set_id_param()
{
    try {
        if (!Utils::is_valid_number(current_request->get_request_param(FILM_ID)))
        throw BadRequest("id is not a number");
        id = stoi(current_request->get_request_param(FILM_ID));
    }
    catch(NotFound)
    {
        throw BadRequest("film id parameter not found");
    }
}

string FilmController::make_film_info_string(Film film)
{

    stringstream film_info;
    film_info.precision(2); 
    film_info << "Details of Film " << film.get_name() << endl
            << "Id = " << film.get_id() << endl
            << "Director = " << film.get_director() << endl
            << "Length = " << film.get_length() << endl
            << "Year = " << film.get_year() << endl
            << "Summary = " << film.get_summary() << endl
            << "Rate = " << film.get_rate() << endl
            << "Price = " << film.get_price() << endl;

    film_info << endl;
    return film_info.str();
}

string FilmController::make_recommendation_string(Film film)
{
    const int RECOM_SIZE = 4;
    const string spacer = " | ";
    vector <Film> films = film_service.get_recommendation_list(film);
    stringstream recom;
    recom.precision(2); 
    recom << "Recommendation Film" << endl;
    recom << "#. Film Id" << spacer << "Film Name" << spacer << "Film Length" << spacer << "Film Director" << endl;
    for (int i = 0; i < RECOM_SIZE && i < films.size(); i++)
        recom << i + 1 << ". " <<  films[i].get_id() << spacer << films[i].get_name() << spacer 
                << films[i].get_length() << spacer << films[i].get_director() << endl;
    
    return recom.str();
}

string FilmController::make_comments_string(Film film)
{
    stringstream comment_info;
    vector <Comment> comments = film.get_comments();
    comment_info << "Comments" << endl;
    for (int i = 0; i < comments.size(); i++)
    {
        comment_info << comments[i].get_id() << ". " << comments[i].get_content() << endl;
        vector <string> replies = comments[i].get_reply();
        for (int j = 0; j < replies.size(); j++)
            comment_info << comments[i].get_id() << "."<<j + 1 << ". "<< replies[j] << endl;
    }
    comment_info << endl;

    return comment_info.str();
}