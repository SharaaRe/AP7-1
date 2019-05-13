#ifndef REQUEST_RECIEVER
#define REQUEST_RECIEVER

class Request;

#include <string>
#include <vector>

#include "Request.h"

class RequestReciever 
{
public:
    Request recieve_request();

private:
    std::string request_line;
    std::vector <string> parse_request();
    void control_format(std::vector<std::string> request_tokens);
    bool check_valid_token(std::string token, std::vector <std::string> valid_tokens);

};

#endif