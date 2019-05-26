#include "LogoutController.h"

#include "Exceptions.h"

LogoutController::LogoutController()
{
    user_manager = UserSessionManagement::get_instance();
}


Response LogoutController::post(Request* request)
{
    current_request = request;
    if (user_manager->get_logged_user() != nullptr)
        user_manager->set_logged_user(nullptr);
    
    else
        throw BadRequest("no user is logged in");
}