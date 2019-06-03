#include "RateHandler.h"

#include "Utils.h"
#include "FilmService.h"
#include "Exceptions.h"

using namespace std;

Response* RateHandler::callback(Request* req)
{
    current_request = req;
    try{
        film_id = Utils::string_integer_value(current_request->getBodyParam(FILM_ID)); 
        score = Utils::string_integer_value(current_request->getBodyParam(SCORE));
        FilmService().rate(film_id, score);
        Response* res = Response::redirect("/films?film_id=" + to_string(film_id) + "&msg=5");
        return res;
    }
    catch(Exception& er)
    {
        throw Server::Exception(er.error());
    }
}