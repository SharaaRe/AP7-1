#include <exception>

#include <string>

// typedef std::exception Exception;

class Exception :public std::exception
{
public:
    Exception(std::string description);
    Exception();
    virtual const std::string error() const throw() = 0;
protected:
    std::string description;
};


class NotFound :public Exception
{
public:
    NotFound(std::string detail) : Exception(detail) {}
    virtual const std::string error() const throw();
    virtual const char* what() const throw();
};

class BadRequest :public Exception
{
public:
    BadRequest(std::string detail) : Exception(detail) {}
    virtual const std::string error() const throw();
    virtual const char* what() const throw();   
};

class PermissionDenied :public Exception
{
public:
    PermissionDenied(std::string detail) : Exception(detail) {}
    virtual const std::string error() const throw();
    virtual const char* what() const throw();    
};