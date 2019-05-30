#include "RepliesController.h"

#include "Utils.h"
#include "FilmService.h"
#include "Exceptions.h"

// using service::Request;
// using service::Response;

service::Response RepliesController::post(service::Request* request)
{
    current_request = request;   
    check_post_params();
    FilmService film_service;
    film_service.reply(film_id, comment_id, content);

    return service::Response(SUCCESSFUL, OK);
}

void RepliesController::check_post_params()
{
    try
    {
        film_id = Utils::string_integer_value(current_request->get_request_param(FILM_ID));
        comment_id = Utils::string_integer_value(current_request->get_request_param(COMMENT_ID));
        content = current_request->get_request_param(CONTENT);
    }
    catch(NotFound& er)
    {
        throw BadRequest("a required params do not exist");
    }
}