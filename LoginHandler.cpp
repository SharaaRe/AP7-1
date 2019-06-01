#include "LoginHandler.h"

#include <string>

#include "Utils.h"
#include "Exceptions.h"
#include "UserService.h"

using namespace std;

Response* LoginHandler::callback(Request* req)
{
    current_request = req;
    try{
        required_params();
        int id = UserService().login(username,password);
        Response* res = Response::redirect("/HomePage");
        res->setSessionId(to_string(id));
        return res;
    }
    catch(Exception& er)
    {
        cout << "User name or password is wrong! "<< er.error() << endl;
        Response* res = Response::redirect("/login");
        return res;
    }
}

void LoginHandler::required_params()
{
    if ((username = current_request->getBodyParam(USERNAME)) == ""
            || (password = current_request->getBodyParam(PASSWORD)) == "")
        
        throw Server::Exception("Username or Password param is missing");

}