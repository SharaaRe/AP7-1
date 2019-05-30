#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Request.h"
#include "Response.h"


class Controller 
{
    public:
        Controller();
        virtual service::Response post(service::Request* request);    
        virtual service::Response get(service::Request* request);
    protected:
        service::Request* current_request;
        

};

#endif