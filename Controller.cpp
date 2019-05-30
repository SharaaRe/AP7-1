#include "Controller.h"

#include "Response.h"
#include "Exceptions.h"

using service::Request;
using service::Response;

Controller::Controller()
{
    current_request = NULL;
}


service::Response Controller::get(service::Request* request)
{
    return Response(ERROR, BadRequest("not matching method and url").error());
}

service::Response Controller::post(service::Request* request)
{
    return Response(ERROR, BadRequest("not matching method and url").error());
}
