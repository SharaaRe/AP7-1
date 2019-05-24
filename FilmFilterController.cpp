#include "FilmFilterController.h"

#include <string>
#include <sstream>

#include "Request.h"
#include "Response.h"
#include "Exceptions.h"
#include "FilmFilterService.h"
#include "UserSessionManagement.h"
#include "FilmService.h"
#include "DataBase.h"
#include "Utils.h"


#define MIN_YEAR "min_year"
#define MAX_YEAR "max_year"
#define PRICE "price"
#define DIRECTOR "director"

using namespace std;

Response FilmFilterController::get(Request* request)
{
    current_request = request;
    check_params();
    FilmFilterService film_filter(DataBase::get_instance()->get_all_films());
    film_filter.filter(name , max_year, min_year, price, rate, director);
    films = film_filter.get_filtered();
    return make_get_film_response();
}


Response FilmFilterController::make_get_film_response()
{
    const string FILM_HEADER = "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director";
    const string spacer = " | ";
    stringstream res;

    res <<FILM_HEADER << endl;

    for (int i = 0; i < films.size(); i++)
    {
        res << i + 1 << ". " << films[i].get_id() << spacer << films[i].get_name() << spacer << films[i].get_length()
                 << spacer << films[i].get_price() << spacer << films[i].get_rate() << spacer << films[i].get_year()
                 << spacer << films[i].get_director() << endl;
    }
    
    return Response(SUCCESSFUL, res.str());
}


void FilmFilterController::check_params()
{
    re_initialize_params();
    try
    {name = current_request->get_request_param(NAME);}
    catch(NotFound& er)
    {}
     
    try 
    {director = current_request->get_request_param(DIRECTOR);}
    catch(NotFound& er)
    {}

    try
    {min_year = Utils::string_integer_value(current_request->get_request_param(MIN_YEAR));}
    catch(NotFound& er)
    {}

    try
    {max_year = Utils::string_integer_value(current_request->get_request_param(MAX_YEAR));}
    catch(NotFound& er)
    {}

    try
    {price = Utils::string_integer_value(current_request->get_request_param(PRICE));}
    catch(NotFound& er)
    {}    
}

void FilmFilterController::re_initialize_params()
{
    name = NOT_FILTERED_ST;
    director = NOT_FILTERED_ST;
    min_year = NOT_FILTERED;
    max_year = NOT_FILTERED;
    price = NOT_FILTERED;
    rate = NOT_FILTERED;
}