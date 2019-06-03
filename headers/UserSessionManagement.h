#ifndef SESSION_MANAGEMENT_H
#define SESSION_MANAGEMENT_H

#include "User.h"
#include "Publisher.h"
#include "Client.h"

class UserSessionManagement 
{
public:
    static UserSessionManagement* get_instance();
    void set_logged_user(User* logged_user);
    void set_logged_user(int session_id);
    void login(int session_id);
    int get_session_id();
    void sign_out();
    User* get_logged_user();
    User* get_logged_user(int session_id);
    Publisher* get_logged_publisher();
    Publisher* get_logged_publisher(int session_id);
    Client* get_logged_client();
    Client* get_logged_client(int session_id);
    bool is_logged_in();
private:
    UserSessionManagement();
    static UserSessionManagement* instance;
    User* logged_user;
};

#endif