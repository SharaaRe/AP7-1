#include "ControllerManager.h"

#include <iostream> //delete it 

#include "SignupController.h"
#include "LoginController.h"

using namespace std;

ControllerManager::ControllerManager()
{
    controllers.insert(pair <std::string, Controller*> (SIGN_UP, new SignupController()));
    controllers.insert(pair <std::string, Controller*> (LOGIN, new LoginController()));
}

ControllerManager::~ControllerManager()
{
    for (map <std::string, Controller*> ::iterator it = controllers.begin(); it != controllers.end(); it++)
        delete (it->second);
}

void ControllerManager::run_controller(Request* request)
{
    response = Response();
    Controller* controller = controllers[request->get_url()];
    switch (request->get_method())
    {
        case GET:
            response = controller->get(request);
            break;
        case POST:
            response = controller->post(request);
            break;            
        case PUT:
            response = controller->put(request);
            break;
        case DELETE:
            response = controller->delete_(request);
            break;
    }
}

Response ControllerManager::get_response()
{
    return response;
}