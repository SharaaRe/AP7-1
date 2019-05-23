#include "FilmController.h"

#include <string>
#include <sstream>

#include "FilmService.h"
#include "FilmFilterController.h"
#include "Utils.h"
#include "Response.h"
#include "Exceptions.h"
#include "Comment.h"
#include "DataBase.h"

#define FILM_ID "film_id"
#define NAME "name"
#define YEAR "year"
#define LENGTH "length"
#define PRICE "price"
#define SUMMERY "summery"
#define DIRECTOR "director"

using namespace std;

FilmController::FilmController()
{}

Response FilmController::get(Request* request)
{
    re_initialize();
    current_request = request;
    if (get_id_param_exist())
    {
        return Response(SUCCESSFUL, make_film_info_string(*DataBase::get_instance()->search_film(id)));
    }
    else
    {   
        FilmFilterController film_filter_controller;
        return film_filter_controller.get(request); 
    }

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

Response FilmController::post(Request* request)
{
    re_initialize();
    current_request = request;
    try
    {
        film_service.add_film(name, year, length, price, summery, director);
        return Response(SUCCESSFUL, OK);
    }
    catch(Exception& er)
    {
        return Response(ERROR, er.error());
    }
}

void FilmController::post_required_params()
{
    name = current_request->get_request_param(NAME);
    string year_string = current_request->get_request_param(YEAR);
    string length_string = current_request->get_request_param(LENGTH);
    string price_string = current_request->get_request_param(PRICE);
    summery = current_request->get_request_param(SUMMERY);
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


Response FilmController::put(Request* request)
{
    current_request = request;
    put_params();
    film_service.edit_film(id, name, year, length, summery, director);
    return Response(SUCCESSFUL, OK);
}

Response FilmController::delete_(Request* request)
{
    re_initialize();
    current_request = request;
    set_id_param();
    film_service.delete_(id);
    Response(SUCCESSFUL, OK);
}

void FilmController::put_params()
{
    re_initialize();

    string year_string, length_string;

    set_id_param();
    try{name = current_request->get_request_param(NAME);}
    catch(NotFound) {}

    try{summery = current_request->get_request_param(SUMMERY);}
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

void FilmController::re_initialize()
{
    name = NOT_CHANGED;
    year = VALUE_NOT_CHANGED;
    length = VALUE_NOT_CHANGED;
    price = VALUE_NOT_CHANGED;
    summery = NOT_CHANGED;
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
    stringstream comment_info;
    vector <Comment> comments = film.get_comments();
    film_info << "Details of Film " << film.get_name() << endl
            << "Id = " << film.get_id() << endl
            << "Director = " << film.get_director() << endl
            << "Length = " << film.get_length() << endl
            << "Year = " << film.get_year() << endl
            << "Rate = " << film.get_rate() << endl
            << "Price = " << film.get_price() << endl;

    comment_info << "Comments" << endl;
    for (int i = 0; i < comments.size(); i++)
    {
        comment_info << comments[i].get_id() << ". " << comments[i].get_content() << endl;
        vector <string> replies = comments[i].get_reply();
        for (int j = 0; j < replies.size(); j++)
            comment_info << comments[i].get_id() << j + 1 << replies[j] << endl;
    }
    
    return film_info.str() + comment_info.str();
}