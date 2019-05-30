#ifndef UT_FLIX_SERVICE
#define UT_FLIX_SERVICE

#include "RequestReciever.h"
#include "ControllerManager.h"
#include "Request.h"
#include "Response.h"
#include "Exceptions.h"

class UTflixService
{
public:
    UTflixService() = default;
    void run();
private:
    service::Request current_request;
    service::Response current_response;
    RequestReciever input;
    ControllerManager controller_manager;

};

#endif