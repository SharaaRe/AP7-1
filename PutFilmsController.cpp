#include "PutFilmsController.h"

using service::Request;
using service::Response;

Response PutFilmsController::post(Request* request)
{
    current_request = request;
    put_params();
    film_service.edit_film(id, name, year, length, summary, director);
    return Response(SUCCESSFUL, OK);
}


Response PutFilmsController::get(Request* request)
{
    return Controller::get(request);
}


