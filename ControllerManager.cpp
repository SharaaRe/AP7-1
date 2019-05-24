#include "ControllerManager.h"

#include <iostream> //delete it 

#include "SignupController.h"
#include "LoginController.h"
#include "FilmController.h"
#include "FollowerController.h"
#include "MoneyController.h"
#include "BuyController.h"
#include "CommentsController.h"
#include "RepliesController.h"
#include "RateController.h"
#include "NotificationsController.h"
#include "NotificationsReadController.h"
#include "PurchasedController.h"
#include "PublishedController.h"
#include "Exceptions.h"
#include "Response.h"

using namespace std;

ControllerManager::ControllerManager()
{
    controllers.insert(pair <std::string, Controller*> (SIGN_UP, new SignupController()));
    controllers.insert(pair <std::string, Controller*> (LOGIN, new LoginController()));
    controllers.insert(pair <std::string, Controller*> (FILMS, new FilmController()));
    controllers.insert(pair <std::string, Controller*> (FOLLOWERS, new FollowerController()));
    controllers.insert(pair <std::string, Controller*> (MONEY, new MoneyController()));
    controllers.insert(pair <std::string, Controller*> (COMMENTS, new CommentsController()));
    controllers.insert(pair <std::string, Controller*> (REPLIES, new RepliesController()));
    controllers.insert(pair <std::string, Controller*> (BUY, new BuyController()));
    controllers.insert(pair <std::string, Controller*> (RATE, new RateController()));
    controllers.insert(pair <std::string, Controller*> (NOTIFICATION, new NotificationsController()));
    controllers.insert(pair <std::string, Controller*> (NOTIFICATION_READ, new NotificationsReadController()));
    controllers.insert(pair <std::string, Controller*> (PURCHASED, new PurchasedController()));
    controllers.insert(pair <std::string, Controller*> (PUBLISHED, new PublishedController()));

    
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