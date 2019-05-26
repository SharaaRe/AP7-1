#include "CommentsController.h"

#include "Request.h"
#include "Response.h"
#include "FilmService.h"
#include "Utils.h"
#include "Exceptions.h"


Response CommentsController::post(Request* request)
{
    current_request = request;
    FilmService film_service;
    check_post_params();
    film_service.comment(film_id, content);

    return Response(SUCCESSFUL, OK);

}




void CommentsController::check_post_params()
{
    try
    {
        film_id = Utils::string_integer_value(current_request->get_request_param(FILM_ID));
        content = current_request->get_request_param(CONTENT);
    }
    catch(NotFound& er)
    {
        throw BadRequest("required params do not exist");
    }
}

void CommentsController::check_delete_params()
{
    try
    {
        film_id = Utils::string_integer_value(current_request->get_request_param(FILM_ID));
        comment_id = Utils::string_integer_value(current_request->get_request_param(COMMENT_ID));
    }
    catch(NotFound& er)
    {
        throw BadRequest("required params do not exist");
    }
    
}