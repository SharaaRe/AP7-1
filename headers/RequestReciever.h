#ifndef REQUEST_RECIEVER
#define REQUEST_RECIEVER

#include <string>
#include <vector>

#include "Request.h"

class RequestReciever
{
public:
    service::Request recieve_request();

private:
    std::string request_line;
    std::vector <std::string> parse_request();
    void control_format(std::vector<std::string> request_tokens);
    bool check_valid_token(std::string token, std::vector <std::string> valid_tokens);
    bool valid_token(std::string token, std::vector <std::string> valid_tokens);

};

#endif