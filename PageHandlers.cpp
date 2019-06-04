#include "PageHandlers.h"

#include "Utils.h"
#include "Exceptions.h"
#include "UserSessionManagement.h"

#define ERROR "error"
#define WRONG_PASS "Wrong username or password!"
#define WRONG_PASS_CODE 1
#define DUP_USER "Username already exists!"
#define DUP_USER_CODE 2
#define NOT_LOGGED_IN "Please login first!"
#define NOT_LOGGED_IN_CODE 3
#define ACCESS_DENIED "No access to this feature!"
#define ACCESS_DENIED_CODE 4
#define SIGNED_OUT "Signed out successfully!"
#define SIGNED_OUT_CODE 0


using namespace std;


PageHandlers::PageHandlers(string file_path)
    :TemplateHandler(file_path)
{};

Response* PageHandlers::callback(Request* req)
{
    if (UserSessionManagement::get_instance()->is_logged_in())
        return Response::redirect("/HomePage");
    else
        return TemplateHandler::callback(req);
    
}

map <string, string> PageHandlers::handle(Request* req)
{
    map <string, string> context;
    try{
        int error_code = Utils::string_integer_value(req->getQueryParam(ERROR));
        switch (error_code)
        {
        case WRONG_PASS_CODE:
            context[ERROR] = WRONG_PASS;
            break;
        case DUP_USER_CODE:
            context[ERROR] = DUP_USER;
            break;
        case NOT_LOGGED_IN_CODE:
            context[ERROR] = NOT_LOGGED_IN;
            break;
        case SIGNED_OUT_CODE:
            context[ERROR] = SIGNED_OUT;
            break;
        
        default:
            break;
        }
    }
    catch(BadRequest& er)
    {
        context[ERROR] = "";   
    }

    return context;
} 