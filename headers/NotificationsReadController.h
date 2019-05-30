#ifndef NOTIFICATIONS_READ_CONTROLLER_H
#define NOTIFICATIONS_READ_CONTROLLER_H

#include "NotificationsController.h"

class NotificationsReadController: public NotificationsController
{
public:
    virtual service::Response get(service::Request* request);
private:
    int limit;
};

#endif