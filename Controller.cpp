#include "Controller.h"

#include "Response.h"
#include "Exceptions.h"

Controller::Controller()
{}

Response* Controller::put(Request* request)
{
    return new Response(ERROR, BadRequest("not matching method and url").what());
}

Response* Controller::get(Request* request)
{
    return new Response(ERROR, BadRequest("not matching method and url").what());
}

Response* Controller::post(Request* request)
{
    return new Response(ERROR, BadRequest("not matching method and url").what());
}

Response* Controller::delete_(Request* request)
{
    return new Response(ERROR, BadRequest("not matching method and url").what());
}