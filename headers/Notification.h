#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class Notification 
{
    Notification(std::string content);
    bool is_read();
private:
    std::string content;
    bool read;
};


#endif