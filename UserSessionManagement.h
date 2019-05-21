#ifndef SESSION_MANAGEMENT_H
#define SESSION_MANAGEMENT_H

class User;
class Client;
class Publisher;

class UserSessionManagement 
{
public:
    static UserSessionManagement* get_instance();
    void set_logged_user(User* logged_user);
    User* get_logged_user();
    Publisher* get_logged_publisher();
    Client* get_logged_client();
    bool is_publisher();
    bool is_admin();
private:
    // UserSessionManagement() = default;
    static UserSessionManagement* instance;
    User* logged_user;
};

#endif