#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <vector>
#include <map>

enum METHODS {GET, PUT, POST, DELETE};

class Request
{
public:
    Request(std::vector<std::string>);
    void print_request(); //this should be deleted
    std::string get_request_param(std::string);
private:
    int method;
    std::string url;
    std::map <std::string, std::string> parameters;
};


#endif