#include "AddFilmHandler.h"

#include "FilmService.h"
#include "Exceptions.h"
#include "UserSessionManagement.h"
#include "Utils.h"


using namespace std;


Response* AddFilmHandler::callback(Request* request)
{
    current_request = request;
    UserSessionManagement::get_instance()->set_logged_user(stoi(request->getSessionId()));

    name = request->getBodyParam(NAME);
    director = request->getBodyParam(DIRECTOR);
    summary = request->getBodyParam(SUMMERY);
    year = request->getBodyParam(YEAR);
    price = request->getBodyParam(PRICE);
    length = request->getBodyParam(LENGTH);
    if (name == KEY_NOT_FOUND || director == KEY_NOT_FOUND || year == KEY_NOT_FOUND 
            || price == KEY_NOT_FOUND || length == KEY_NOT_FOUND || summary == KEY_NOT_FOUND)

        throw Server::Exception("A film parameter missing");
    try{
        FilmService().add_film(name, Utils::string_integer_value(year), Utils::string_integer_value(length), 
                Utils::string_integer_value(price), summary, director);
        Response* res = Response::redirect("/HomePage");
        return res;
    }
    catch(PermissionDenied& er)
    {
        Response* res = Response::redirect("/HomePage?error=4");
    }
    catch(Exception& er)
    {
        throw Server::Exception(er.error());
    }
}