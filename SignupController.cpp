#include "SignupController.h"

#include <string>

#include "DataBase.h"
#include "User.h"
#include "Client.h"
#include "Publisher.h"
#include "Request.h"
#include "Response.h"
#include "UserService.h"
#include "Utils.h"
#include "Exceptions.h"
#include "md5.h"

#define TRUE "true"
#define FALSE "false"

using namespace std;

Response SignupController::post(Request* req)
{
    current_request = req;
    publisher_flag = false;

    User* new_user;
    post_required_params();
    post_required_params();
    publisher_flag = is_publisher();
    UserService().signup(email, username, password, age, publisher_flag);

return Response(SUCCESSFUL, OK);
}

void SignupController::post_required_params()
{
    try
    {
        username = current_request->get_request_param(USERNAME);
        password = md5(current_request->get_request_param(PASSWORD));

        email = current_request->get_request_param(EMAIL);
        if (! Utils::is_valid_email(email))
            throw BadRequest("email is not valid");

        if (!Utils::is_valid_number(current_request->get_request_param(AGE))
                && stoi(current_request->get_request_param(AGE)) <= 0)
            throw BadRequest("age is not valid");
        else 
            age = stoi (current_request->get_request_param(AGE));
    }
    catch(NotFound& er)
    {
        throw BadRequest("required params are not complete");
    }
}




bool SignupController::is_publisher()
{
    const string NOT_ASSIGNED = "not assigned";
    string publisher_flag = NOT_ASSIGNED;
    try
    {
        publisher_flag = current_request->get_request_param(PUBLISHER_PARAM);
    }
    catch(Exception& er)
    {
        return false;
    }
    if (publisher_flag != TRUE && publisher_flag != FALSE && publisher_flag != NOT_ASSIGNED)
            throw BadRequest("value of publisher flag is not valid");

    return publisher_flag == TRUE? true : false;
}

