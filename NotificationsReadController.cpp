#include "NotificationsReadController.h"


#include "Utils.h"
#include "Request.h"
#include "Exceptions.h"
#include "UserService.h"

#define LIMIT "limit"

Response NotificationsReadController ::get(Request* request)
{
    current_request = request;
    UserService user_service;
    try
    {
        limit = Utils::string_integer_value(current_request->get_request_param(LIMIT));
    }
    catch(NotFound er)
    {
        throw BadRequest("limit is not a number");
    }

    return make_notification_response(user_service.get_notifications(true));
}