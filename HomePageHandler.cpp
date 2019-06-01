#include "HomePageHandler.h"

#include <sstream>
#include <iostream>

#include "UserSessionManagement.h"
#include "FilmFilterService.h"
#include "Exceptions.h"
#include "DataBase.h"

using namespace std;


HomePageHandler::HomePageHandler(string file_path)
    :TemplateHandler(file_path)
{}


Response* HomePageHandler::callback(Request* request)
{
    // cout << "start callback" << endl;
    published_films.clear();
    films.clear();
    current_request = request;
    try{
        UserSessionManagement::get_instance()->get_logged_publisher();
        publisher = true;
        publisher_handler(request);
        client_handler(request);
    }
    catch(PermissionDenied& er)
    {

        UserSessionManagement::get_instance()->get_logged_client();
        publisher = false;
        client_handler(request);
    }
    catch(BadRequest& er)
    {
        res = Response::redirect("/login");
        return res;
    }

    return TemplateHandler::callback(request);
}


void HomePageHandler::publisher_handler(Request* request)
{
    published_films = film_service.get_published();
    try{
        string director_filter = current_request->getQueryParam(DIRECTOR);
        if (director_filter == KEY_NOT_FOUND )
            director_filter = NOT_FILTERED_ST;
        cout << "director filter is: " << director_filter << endl;
        FilmFilterService film_filer(published_films);
        film_filer.filter(NOT_FILTERED_ST, NOT_FILTERED, NOT_FILTERED, NOT_FILTERED, NOT_FILTERED, director_filter);
        film_filer.filter_not_available();
        published_films = film_filer.get_filtered();
    }
    catch(Exception& er)
    {
        throw Server::Exception(er.error());
    }   
}


void HomePageHandler::client_handler(Request* req)
{
    films = DataBase::get_instance()->get_all_films();
    try
    {
        Client* client = UserSessionManagement::get_instance()->get_logged_client();
        string director_filter = current_request->getQueryParam(DIRECTOR);
        if (director_filter == KEY_NOT_FOUND)
            director_filter = NOT_FILTERED_ST;
        cout << "director filter is: " << director_filter << endl;
        FilmFilterService film_filer(films);
        film_filer.filter(NOT_FILTERED_ST, NOT_FILTERED, NOT_FILTERED, client->get_credit(), NOT_FILTERED, director_filter);
        film_filer.filter_not_available();
        films = film_filer.get_filtered();
    }
    catch(Exception& er)
    {
        throw Server::Exception(er.error());
    }   


}


map <string, string> HomePageHandler::handle(Request* request)
{

    map <string, string> context;
    context["username"] = UserSessionManagement::get_instance()->get_logged_user()->get_username();
    if (publisher)
        context["publisher"] = "true";
    else 
        context["publisher"] = "false";
    int n = published_films.size();
    context["n"] = to_string(n);
    for (int i = 0; i < published_films.size(); i++)
    {
        string index = to_string(i);
        stringstream rate;
        context["id" + index] = to_string(published_films[i].get_id());
        context["name" + index] = published_films[i].get_name();
        context["price" + index] = to_string(published_films[i].get_price());
        context["year" + index] = to_string(published_films[i].get_year());
        context["length" + index] = to_string(published_films[i].get_length());
        rate.precision(2);
        rate << published_films[i].get_rate();
        context["rate" + index] = rate.str();
        context["director" + index] = published_films[i].get_director();
    }
    int n2 = n + films.size();
    context["n2"] = to_string(n2);
    for (int i = n; i < n + films.size(); i++)
    {        
        string index = to_string(i);
        stringstream rate;
        context["id" + index] = to_string(films[i].get_id());
        context["name" + index] = films[i].get_name();
        context["price" + index] = to_string(films[i].get_price());
        context["year" + index] = to_string(films[i].get_year());
        context["length" + index] = to_string(films[i].get_length());
        rate.precision(2);
        rate << films[i].get_rate();
        context["rate" + index] = rate.str();
        context["director" + index] = films[i].get_director();
        }
    return context;
}