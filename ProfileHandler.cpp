#include "ProfileHandler.h"

#include <sstream>

#include "Film.h"
#include "UserSessionManagement.h"
#include "FilmService.h"
#include "Exceptions.h"

#define ADD_CREDIT_MSG "Your credit increased successfully!"


using namespace std;

ProfileHandler::ProfileHandler(string file_path)
    :TemplateHandler(file_path)
{}


Response* ProfileHandler::callback(Request* req)
{
    try{
        purchased_films = FilmService().get_purchased();
        return TemplateHandler::callback(req);
    }
    catch(PermissionDenied& er)
    {
        throw Server::Exception("admin does not have access to this page!");
    }
    catch(BadRequest& er)
    {
        Response* res = Response::redirect("/login?error=3");
        return res;
    }
}


map <string, string> ProfileHandler::handle(Request* req)
{
    map <string, string> context;
    User* logged_user = UserSessionManagement::get_instance()->get_logged_user();
    context["username"] = logged_user->get_username();
    context["credit"] = to_string(logged_user->get_money());
    int n = purchased_films.size();
    cout << n << endl;
    context["n"] = to_string(n);

    for (int i = 0; i < purchased_films.size(); i++)
    {
        string index = to_string(i);
        stringstream rate;
        context["id" + index] = to_string(purchased_films[i].get_id());
        context["name" + index] = purchased_films[i].get_name();
        context["price" + index] = to_string(purchased_films[i].get_price());
        context["year" + index] = to_string(purchased_films[i].get_year());
        context["length" + index] = to_string(purchased_films[i].get_length());
        rate.precision(2);
        rate << purchased_films[i].get_rate();
        context["rate" + index] = rate.str();
        context["director" + index] = purchased_films[i].get_director();
    }
    return context;
}