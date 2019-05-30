#include "server.hpp"

class SignupHandler: public RequestHandler
{
public:
    virtual Response* callback(Request* req);
private:
    Request* current_request;
    std::string username;
    std::string password;
    std::string email;
    int age;
    bool publisher;
    void post_required_params();
    bool is_publisher();
};
