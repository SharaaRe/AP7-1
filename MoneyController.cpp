#include "MoneyController.h"

#include <sstream>

#include "UserService.h"
#include "UserSessionManagement.h"
#include "Client.h"
#include "Utils.h"
#include "Exceptions.h"
#include "UTflix.h"

#define AMOUNT "amount"

Response MoneyController::post(Request* request)
{

    if(request->number_of_params() > 0)
    {
        current_request = request;
        Client* client = UserSessionManagement::get_instance()->get_logged_client();
        client->increase_credit(Utils::string_integer_value(request->get_request_param(AMOUNT)));
    }
    else
    {
        Publisher* publisher = UserSessionManagement::get_instance()->get_logged_publisher();
        UTflix::get_instance()->pay_publisher_debt(publisher);
    }

    return Response(SUCCESSFUL, OK);
}

Response MoneyController::get(Request* request)
{
    User* user = UserSessionManagement::get_instance()->get_logged_user();
    int credit = user->get_money();
    std::stringstream credit_stream;
    credit_stream << credit << std::endl;
    return Response(SUCCESSFUL, credit_stream.str());
}