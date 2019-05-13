#include "Exceptions.h"

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
    return "Permission Denied";
}