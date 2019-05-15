#include <exception>

#include <string>

class NotFound :public std::exception
{
public:
    NotFound(std::string detail);
    virtual const char* what() const throw();
private:
    std::string details;
};

class BadRequest :public std::exception
{
public:
    BadRequest(std::string detail);
    virtual const char* what() const throw();
private:
    std::string details;    
};

class PermissionDenied :public std::exception
{
public:
    PermissionDenied(std::string detail);
    virtual const char* what() const throw();
private:
    std::string details;    
};