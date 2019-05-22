#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Request.h"
#include "Response.h"

class Response;

class Controller 
{
    public:
        Controller();
        virtual Response put(Request* request);
        virtual Response get(Request* request);
        virtual Response post(Request* request);
        virtual Response delete_(Request* request);
    protected:
        Request* current_request;
        

};

#endif