#include "FollowerController.h"

#include <sstream>

#include "Utils.h"
#include "Exceptions.h"
#include "Response.h"
#include "Client.h"

using namespace std;
// using service::Request;
// using service::Response;

service::Response FollowerController::post(service::Request* request)
{

    current_request = request;
    int id = Utils::string_integer_value(request->get_request_param(USER_ID));

    user_service.follow(id);

    return service::Response(SUCCESSFUL, OK);
}


service::Response FollowerController::get(service::Request* request)
{

    current_request = request;
    return get_follower_response(user_service.get_followers());
    
}


service::Response FollowerController::get_follower_response (vector <const Client*> clients)
{
    stringstream res;
    res << "List of Followers" << endl;
    res << "#. User Id | User Username | User Email" << endl;
    for (int i = 0; i < clients.size(); i++)
    {
        res << i + 1 << ". " << clients[i]->get_id() << " | "
                 << clients[i]->get_username() << " | " << clients[i]->get_email() << endl;
    }

    return service::Response(SUCCESSFUL,  res.str());
}