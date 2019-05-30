#include "DeleteCommentsController.h"

#include "FilmService.h"

using service::Request;
using service::Response;

service::Response DeleteCommentsController::post(service::Request* request)
{
    current_request = request;
    FilmService film_service;
    check_delete_params();
    film_service.delete_comment(film_id, comment_id);

    return Response(SUCCESSFUL, OK);   
}