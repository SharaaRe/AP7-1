#include "ServerManager.h"

#include <iostream>

#include "SignupHandler.h"
#include "LoginHandler.h"

ServerManager::ServerManager()
{
    std::cout << "server manager" << std::endl;
    try{
    std::cout << "something" << std::endl;
    my_server.setNotFoundErrPage("APHTTP/static/404.html");    
    my_server.get("/signup", new ShowPage("APHTTP/static/mine/signup.html"));
    my_server.post("/singup", new SignupHandler());
    my_server.get("/login", new ShowPage("APHTTP/static/mine/login.html"));
    my_server.post("/singup", new LoginHandler());
    // my_server.post("/HomePage", new HomePageHandler());
    }
    catch(Server::Exception& er)
    {
        std::cout << er.getMessage() << std::endl;
    }
}

void ServerManager::run()
{
    my_server.run();
}