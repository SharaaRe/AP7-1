#include "LoginController.h"

#include "Response.h"
#include "Request.h"
#include "Utils.h"
#include "Exceptions.h"
#include "UserService.h"
#include "UserService.h"
#include "md5.h"

// using service::Request;
// using service::Response;

service::Response LoginController::post(service::Request* req)
{
    current_request = req;

    post_required_params();
    UserService().login(req->get_request_param(USERNAME),
            md5(req->get_request_param(PASSWORD)));
    
    return service::Response(SUCCESSFUL, OK);
}

void LoginController::post_required_params()
{
    try
    {
        current_request->get_request_param(USERNAME);
        current_request->get_request_param(PASSWORD);
    }
    catch(NotFound& er)
    {
        throw BadRequest("a required parameter has not found");
    }
}