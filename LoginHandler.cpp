#include "LoginHandler.h"

#include <string>

#include "Utils.h"
#include "Exceptions.h"
#include "UserService.h"

using namespace std;

Response* LoginHandler::callback(Request* req)
{
    current_request = req;

    required_params();
    int id = UserService().login(username,password);
    Response* res = new Response;
    res->setSessionId(to_string(id));
    res->redirect("/HomePage");
    // return Response(SUCCESSFUL, OK);
}

void LoginHandler::required_params()
{
    try
    {
        current_request->getBodyParam(USERNAME);
        current_request->getBodyParam(PASSWORD);
    }
    catch(NotFound& er)
    {
        throw BadRequest("a required parameter has not found");
    }
}