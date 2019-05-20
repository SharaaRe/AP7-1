#include <string>

#include "Exceptions.h"


using namespace std;

Exception::Exception(std::string _description)
    :exception(), description(_description)
{}


const string BadRequest::error() const throw()
{
    string response = "Bad Request";
    response += "  details:  " + description;
    return response;

}

const string NotFound::error() const throw()
{
    string response = "Not Found";
    response += "  details:  " + description;
    return response.c_str();
}



const string PermissionDenied::error() const throw()
{
    string response = "Permission Denied";
    response += "  details:  " + description;
    return response.c_str();
}

const char* BadRequest::what() const throw()
{
    return "Bad Request";

}

const char* NotFound::what() const throw()

{
    return "Not Found";
}



const char* PermissionDenied::what() const throw()
{
    return "Permissoin Denied";
}

