#include "ControllerManager.h"

#include <iostream> //delete it 

#include "SignupController.h"
#include "LoginController.h"
#include "LogoutController.h"
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
#include "PutFilmsController.h"
#include "DeleteFilmsController.h"
#include "DeleteCommentsController.h"
#include "Exceptions.h"
#include "Response.h"

using namespace std;

ControllerManager::ControllerManager()
{
    controllers.insert(pair <std::string, Controller*> (SIGN_UP, new SignupController()));
    controllers.insert(pair <std::string, Controller*> (LOGIN, new LoginController()));
    controllers.insert(pair <std::string, Controller*> (LOGOUT, new LogoutController()));
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
    controllers.insert(pair <std::string, Controller*> (PUT_FILMS, new PutFilmsController()));
    controllers.insert(pair <std::string, Controller*> (DELETE_FILMS, new DeleteFilmsController()));
    controllers.insert(pair <std::string, Controller*> (DELETE_COMMENTS, new DeleteCommentsController()));
    controllers.insert(pair <std::string, Controller*> (LOGOUT, new LogoutController()));

    
}

ControllerManager::~ControllerManager()
{
    for (auto it = controllers.begin(); it != controllers.end(); it++)
        delete (it->second);
}

void ControllerManager::run_controller(Request* request)
{
    response = Response();
    Controller* controller;
    if (controllers.find(request->get_url()) != controllers.end())
        controller = controllers[request->get_url()];
    else
        throw NotFound("url not found");
    
    switch (request->get_method())
    {
        case GET:
            response = controller->get(request);
            break;
        case POST:
            response = controller->post(request);
            break;            
    }
}

Response ControllerManager::get_response()
{
    return response;
}