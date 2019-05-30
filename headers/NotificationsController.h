#ifndef NOTIFICATIONS_CONTROLLER_H
#define NOTIFICATIONS_CONTROLLER_H

#include <string>
#include <vector>

#include "Controller.h"


#define NO_LIMIT -1

class NotificationsController: public Controller
{
public:
    virtual service::Response get(service::Request* request);
protected:
    service::Response make_notification_response(std::vector <std::string> notifs, int limit = NO_LIMIT);
};

#endif
