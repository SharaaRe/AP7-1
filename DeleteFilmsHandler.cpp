#include "DeleteFilmsHandler.h"

#include "FilmService.h"
#include "Utils.h"
#include "Exceptions.h"

using namespace std;

Response* DeleteFilmsHandler::callback(Request* req)
{
    current_request = req;
    try
    {
        int film_id = Utils::string_integer_value(req->getBodyParam(FILM_ID));
        FilmService().delete_(film_id);
        Response* res = Response::redirect("/HomePage");
        return res;
    }
    catch(Exception& e)
    {
        throw Server::Exception(e.error());
    }
    
}