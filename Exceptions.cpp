#include <string>

#include "Exceptions.h"

using namespace std;

const char* BadRequest::what() const throw()
{
    string response = "Bad Request";
    response += "  details:  " + details;
    return response.c_str();

}

BadRequest::BadRequest(std::string _detail)
    :exception(), details(_detail)
{}

const char* NotFound::what() const throw()
{
    string response = "Not Found";
    response += "  details:  " + details;
    return response.c_str();
}

NotFound::NotFound(std::string _detail)
    :exception(), details(_detail)
{}

const char* PermissionDenied::what() const throw()
{
    string response = "Permission Denied";
    response += "  details:  " + details;
    return response.c_str();
}

PermissionDenied::PermissionDenied(std::string _detail)
    :exception(), details(_detail)
{}