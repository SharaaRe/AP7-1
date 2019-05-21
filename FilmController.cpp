#include "FilmController.h"

#include "FilmService.h"
#include "Utils.h"
#include "Response.h"
#include "Exceptions.h"

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
    try
    {
        current_request = request;
        put_params();
        film_service.edit_film(id, name, year, length, summery, director);
        return Response(SUCCESSFUL, OK);
    }
    catch(Exception& er)
    {
        return Response(ERROR, er.error());
    }

}

Response FilmController::delete_(Request* request)
{
    try
    {
        re_initialize();
        current_request = request;
        set_id_param();
        film_service.delete_(id);
        Response(SUCCESSFUL, OK);
    }
    catch(Exception& er)
    {
        return Response(ERROR, er.error());
    }

}

void FilmController::put_params()
{
    re_initialize();

    string year_string, length_string;

    set_id_param();
    try{name = current_request->get_request_param(NAME);}
    catch(NotFound) {}

    try{summery = current_request->get_request_param(NAME);}
    catch(NotFound) {}

    try{director = current_request->get_request_param(NAME);}
    catch(NotFound) {}    

    try{
        year_string = current_request->get_request_param(NAME);
        if (Utils::is_valid_number(year_string))
            year = stoi(year_string);
    }
    catch(NotFound) {}

    try{
        length_string = current_request->get_request_param(NAME);
        if (Utils::is_valid_number(length_string))
        year = stoi(length_string);
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