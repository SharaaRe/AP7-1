#include "Controller.h"

#include "Response.h"
#include "Exceptions.h"

Controller::Controller()
{
    current_request = NULL;
}


Response Controller::get(Request* request)
{
    return Response(ERROR, BadRequest("not matching method and url").error());
}

Response Controller::post(Request* request)
{
    return Response(ERROR, BadRequest("not matching method and url").error());
}
