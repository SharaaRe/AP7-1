#include <string>

#include "Exceptions.h"

#define NOT_FOUND_EX "Not Found\n"
#define BAD_REQUEST_EX "Bad Request\n"
#define PERMISSION_DENIED "Permission Denied\n"



using namespace std;

Exception::Exception(std::string _description)
    :exception(), description(_description)
{}


const string BadRequest::error() const throw()
{
    string response = BAD_REQUEST_EX;
    response += "  details:  " + description + "\n";
    return response;

}

const string NotFound::error() const throw()
{
    string response = NOT_FOUND_EX;
    response += "  details:  " + description + "\n";
    return response.c_str();
}



const string PermissionDenied::error() const throw()
{
    string response = PERMISSION_DENIED;
    response += "  details:  " + description + "\n";
    return response.c_str();
}

const char* BadRequest::what() const throw()
{
    return BAD_REQUEST_EX;

}

const char* NotFound::what() const throw()

{
    return NOT_FOUND_EX;
}



const char* PermissionDenied::what() const throw()
{
    return PERMISSION_DENIED;
}

