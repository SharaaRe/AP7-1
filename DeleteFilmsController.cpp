#include "DeleteFilmsController.h"


Response DeleteFilmsController::post(Request* request)
{
    re_initialize();
    current_request = request;
    set_id_param();
    film_service.delete_(id);
    return Response(SUCCESSFUL, OK);
}

Response DeleteFilmsController::get(Request* request)
{
    return Controller::get(request);
}