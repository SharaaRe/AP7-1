#include "MoneyController.h"

#include "UserService.h"
#include "UserSessionManagement.h"
#include "Client.h"
#include "Utils.h"
#include "Exceptions.h"
#include "UTflix.h"

#include <iostream>

#define AMOUNT "amount"

Response MoneyController::post(Request* request)
{

    if(request->number_of_params() > 0)
    {
        current_request = request;
        Client* client = UserSessionManagement::get_instance()->get_logged_client();
        client->increase_credit(Utils::string_integer_value(request->get_request_param(AMOUNT)));

        std::cout << client->get_credit() << std::endl;
    }
    else
    {
        Publisher* publisher = UserSessionManagement::get_instance()->get_logged_publisher();
        UTflix::get_instance()->pay_publisher_debt(publisher);
    }

    return Response(SUCCESSFUL, OK);

}