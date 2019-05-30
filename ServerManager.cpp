#include "ServerManager.h"

#include "SignupHandler.h"
#include "LoginHandler.h"

ServerManager::ServerManager()
{
    my_server.get("/signup", new ShowPage("/static/mine/signup.html"));
    my_server.post("/singup", new SignupHandler());
    my_server.get("/login", new ShowPage("/static/mine/login.html"));
    my_server.post("/singup", new LoginHandler());
    // my_server.post("/HomePage", new HomePageHandler());
}

void ServerManager::run()
{
    my_server.run();
}