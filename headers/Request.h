#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <vector>
#include <map>

enum METHODS {GET_MINE, POST_MINE};

#define GET_ "GET"
#define POST_ "POST"

#define SIGN_UP "signup"
#define LOGIN "login"
#define LOGOUT "logout"
#define FILMS "films"
#define PUBLISHED "published"
#define REPLIES "replies"
#define COMMENTS "comments"
#define FOLLOWERS "followers"
#define MONEY "money"
#define BUY "buy"
#define RATE "rate"
#define PURCHASED "purchased"
#define NOTIFICATION "notifications"
#define NOTIFICATION_READ "notifications/read"
#define PUT_FILMS "put_films"
#define DELETE_FILMS "delete_films"
#define DELETE_COMMENTS "delete_comments"
namespace service
{
class Request
{
public:
    Request(std::vector<std::string>);
    Request() = default;
    void print_request();
    std::string get_request_param(std::string);
    int get_method();
    std::string get_url();
    int number_of_params();
private:
    int method;
    std::string url;
    std::map <std::string, std::string> parameters;
};
};


#endif