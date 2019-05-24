#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <vector>
#include <map>

enum METHODS {GET, PUT, POST, DELETE};

#define GET_ "GET"
#define PUT_ "PUT"
#define DELETE_ "DELETE"
#define POST_ "POST"

#define SIGN_UP "signup"
#define LOGIN "login"
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

class Request
{
public:
    Request(std::vector<std::string>);
    Request() = default;
    void print_request(); //this should be deleted
    std::string get_request_param(std::string);
    int get_method();
    std::string get_url();
    int number_of_params();
private:
    int method;
    std::string url;
    std::map <std::string, std::string> parameters;
};


#endif