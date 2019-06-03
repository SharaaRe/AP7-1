#include "BuyHandler.h"


#include "FilmService.h"
#include "Utils.h"
#include "Exceptions.h"

using namespace std;

Response* BuyHandler::callback(Request* req)
{
    current_request = req;
    try{
        int film_id = Utils::string_integer_value(req->getBodyParam(FILM_ID));
        FilmService().buy(film_id);
        Response* res = Response::redirect("/films?film_id=" + to_string(film_id) + "&msg=6");
        return res;
    }
    catch(PermissionDenied& er)
    {
        Response* res = Response::redirect("/films?film_id=" + req->getBodyParam(FILM_ID) + "&error=4");

    }
    catch(Exception& er)
    {
        throw Server::Exception(er.error());
    }
    
}