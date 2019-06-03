#include "MoneyHandler.h"

#include "UserService.h"
#include "Utils.h"
#include "Exceptions.h"

Response* MoneyHandler::callback(Request* req)
{
    try
    {
        int amount = Utils::string_integer_value(req->getBodyParam("amount"));
        UserService().post_money(amount);
        Response* res = Response::redirect("/profile?msg=7");
        return res;
    }
    catch(BadRequest& er)
    {
        // Response* res = Response::redirect("/login?error=3");
        // return res;
        throw Server::Exception(er.error());
    }
    catch(PermissionDenied& er)
    {
        throw Server::Exception(er.error());
    }
}