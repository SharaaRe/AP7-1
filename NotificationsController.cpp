#include "NotificationsController.h"

#include <sstream>

#include <iostream>

#include "Request.h"
#include "UserService.h"

using namespace std;
// using service::Request;
// using service::Response;

service::Response NotificationsController::get(service::Request* request)
{
    current_request = request;
    UserService user_service;
    return make_notification_response(user_service.get_notifications());
    
}

service::Response NotificationsController::make_notification_response(vector <string> notifs, int limit)
{

    if (limit == NO_LIMIT || limit > notifs.size())
        limit = notifs.size();
    stringstream res;
    res << "#. Notification Message" << endl;
    int size = notifs.size();
    for (int i = size - 1; i >= size - limit; i--)
    {
        res << size - i << ". " << notifs[i] << endl;
    }
    return service::Response(SUCCESSFUL, res.str());
}