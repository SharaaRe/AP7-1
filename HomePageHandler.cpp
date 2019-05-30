#include "HomePageHandler.h"

#include <sstream>

#include "UserSessionManagement.h"
#include "FilmFilterService.h"

using namespace std;


HomePageHandler::HomePageHandler(string file_path)
    :TemplateHandler(file_path)
{}


Response* HomePageHandler::callback(Request* request)
{
    current_request = request;
    published_films = film_service.get_published();
    string director_filter = current_request->getBodyParam(DIRECTOR);
    FilmFilterService film_filer(published_films);
    film_filer.filter(NOT_FILTERED_ST, NOT_FILTERED, NOT_FILTERED, NOT_FILTERED, NOT_FILTERED, director_filter);
    published_films = film_filer.get_filtered();

}

map <string, string> HomePageHandler::handle(Request* request)
{
    map <string, string> context;
    context["n"] = to_string(published_films.size());
    for (int i = 0; i < published_films.size(); i++)
    {
        string index = to_string(i);
        stringstream rate;
        context["name" + index] = published_films[i].get_name();
        context["price" + index] = to_string(published_films[i].get_price());
        context["year" + index] = to_string(published_films[i].get_year());
        context["length" + index] = to_string(published_films[i].get_length());
        rate << published_films[i].get_rate();
        context["rate" + index] = rate.str();
        context["director" + index] = published_films[i].get_director();
    }

    return context;
}