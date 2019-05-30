#include "DeleteFilmsController.h"


using service::Request;
using service::Response;

service::Response DeleteFilmsController::post(service::Request* request)
{
    re_initialize();
    current_request = request;
    set_id_param();
    film_service.delete_(id);
    return Response(SUCCESSFUL, OK);
}

service::Response DeleteFilmsController::get(service::Request* request)
{
    return Controller::get(request);
}