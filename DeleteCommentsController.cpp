#include "DeleteCommentsController.h"


Response DeleteCommentsController::post(Request* request)
{
     current_request = request;
    FilmService film_service;
    check_delete_params();
    film_service.delete_comment(film_id, comment_id);

    return Response(SUCCESSFUL, OK);   
}