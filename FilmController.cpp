#include "FilmController.h"

#include "FilmService.h"
#include "Utils.h"
#include "Response.h"
#include "Exceptions.h"

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

void FilmController::re_initialize()
{
    name = "";
    year = 0;
    length = 0;
    price = 0;
    summery = "";
    director = "";
}