#include "LogoutController.h"

#include "Exceptions.h"


#include <iostream>

LogoutController::LogoutController()
{
    user_manager = UserSessionManagement::get_instance();
}


Response LogoutController::post(Request* request)
{
    current_request = request;
    user_manager->sign_out();
    return Response(SUCCESSFUL, OK);
}