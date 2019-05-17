#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Request.h"
class Response;

class Controller 
{
    public:
        Controller();
        virtual Response* put(Request* request);
        virtual Response* get(Request* request);
        virtual Response* post(Request* request);
        virtual Response* delete_(Request* request);
    protected:
        Request* current_request;
        virtual void check_required_params(int method);
        virtual void check_optional_params(int method);
};

#endif