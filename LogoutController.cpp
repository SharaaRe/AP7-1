#include "LogoutController.h"

#include "Exceptions.h"


#include <iostream>

using service::Request;
using service::Response;

LogoutController::LogoutController()
{
    user_manager = UserSessionManagement::get_instance();
}


service::Response LogoutController::post(service::Request* request)
{
    current_request = request;
    user_manager->sign_out();
    return service::Response(SUCCESSFUL, OK);
}