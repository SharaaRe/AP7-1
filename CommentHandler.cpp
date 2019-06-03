#include "CommentHandler.h"

#include "Exceptions.h"
#include "Utils.h"
#include "FilmService.h"

using namespace std;

Response* CommentHandler::callback(Request* req)
{
    try{
        int film_id = Utils::string_integer_value(req->getBodyParam(FILM_ID));
        std::string content = req->getBodyParam(CONTENT);
        if (content == KEY_NOT_FOUND)
            throw Server::Exception("content is empty!");
        FilmService().comment(film_id, content);
        return Response::redirect("films?film_id=" + to_string(film_id) + "&msg=8");
    }
    catch(Exception& er)
    {
        throw Server::Exception(er.error());
    }
}