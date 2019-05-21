#include "Notification.h"


Notification::Notification(std::string _content)
    :content(_content), read(false)
{}

bool Notification::is_read()
{
    return read;
}
