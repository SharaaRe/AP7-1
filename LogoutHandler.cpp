#include "LogoutHandler.h"

#include "UserService.h"

Response* LogoutHandler::callback(Request* req)
{
    UserService().logout();
    Response* res = Response::redirect("/login?error=0");
    res->setSessionId("");
    return res;
}