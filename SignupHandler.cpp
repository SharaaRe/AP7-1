#include "SignupHandler.h"

#include "UserService.h"
#include "UserSessionManagement.h"
#include "Utils.h"
#include "Exceptions.h"


#define TRUE "true"
#define FALSE "false"

using namespace std;

Response* SignupHandler::callback(Request* req)
{
    current_request = req;
    publisher = false;
    post_required_params();
    post_required_params();
    publisher = is_publisher();
    UserService().signup(email, username, password, age, publisher);
    
    Response* res = new Response;
    UserSessionManagement* user_manager = UserSessionManagement::get_instance();
    res->setSessionId(to_string(user_manager->get_session_id()));
    res->redirect("/HomePage");


    return res;
}


void SignupHandler::post_required_params()
{
    try
    {
        username = current_request->getBodyParam(USERNAME);
        password = current_request->getBodyParam(PASSWORD);

        email = current_request->getBodyParam(EMAIL);
        if (! Utils::is_valid_email(email))
            throw BadRequest("email is not valid");

        if (!Utils::is_valid_number(current_request->getBodyParam(AGE))
                && stoi(current_request->getBodyParam(AGE)) <= 0)
            throw BadRequest("age is not valid");
        else 
            age = stoi (current_request->getBodyParam(AGE));
    }
    catch(NotFound& er)
    {
        throw BadRequest("required params are not complete");
    }
}




bool SignupHandler::is_publisher()
{
    const string NOT_ASSIGNED = "not assigned";
    string publisher_flag = NOT_ASSIGNED;
    try
    {
        publisher_flag = current_request->getBodyParam(PUBLISHER_PARAM);
    }
    catch(Exception& er)
    {
        return false;
    }
    if (publisher_flag != TRUE && publisher_flag != FALSE && publisher_flag != NOT_ASSIGNED)
            throw BadRequest("value of publisher flag is not valid");

    return publisher_flag == TRUE? true : false;
}

