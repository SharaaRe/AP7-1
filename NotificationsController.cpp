#include "NotificationsController.h"

#include <sstream>

#include "Request.h"
#include "UserService.h"

using namespace std;

Response NotificationsController::get(Request* request)
{
    current_request = request;
    UserService user_service;
    return make_notification_response(user_service.get_notifications());
    
}

Response NotificationsController::make_notification_response(vector <string> notifs, int limit)
{
    if (limit = NO_LIMIT || limit > notifs.size())
        limit = notifs.size();
    stringstream res;
    int size = notifs.size();
    for (int i = size - 1; i >= size - limit; i--)
    {
        res << size - i << ". " << notifs[i] << endl;
    }
    return Response(SUCCESSFUL, res.str());
}