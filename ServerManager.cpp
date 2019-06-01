#include "ServerManager.h"

#include <iostream>

#include "SignupHandler.h"
#include "LoginHandler.h"
#include "HomePageHandler.h"
#include "AddFilmHandler.h"
#include "DeleteFilmsHandler.h"

#include "UserService.h"
#include "FilmService.h"
#include "Exceptions.h"
#include "UserSessionManagement.h"

ServerManager::ServerManager()
{
    std::cout << "server manager" << std::endl;
    try{
    fake_initializer();
    }
    catch(Exception& er)
    {
        std::cout << er.error() << std::endl;
    }

    try{
        std::cout << "something" << std::endl;
        my_server.setNotFoundErrPage("APHTTP/static/404.html");    
        my_server.get("/signup", new ShowPage("APHTTP/static/mine/signup.html"));
        my_server.post("/signup", new SignupHandler());
        my_server.get("/login", new ShowPage("APHTTP/static/mine/login.html"));
        my_server.post("/login", new LoginHandler());
        my_server.get("/HomePage", new HomePageHandler("APHTTP/static/mine/PublisherHomePage.html"));
        my_server.post("/films", new AddFilmHandler());
        my_server.post("/delete_films", new DeleteFilmsHandler());
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

void ServerManager::fake_initializer()
{
    FilmService fs;
    UserService us;
    us.signup("norouzi.sharaa@gmail.com", "sharaa", "159951", 22, true);
    fs.add_film("film1", 1999, 80, 80, "summary_of_film_1", "director_1");
    fs.add_film("film2", 1999, 80, 1000, "summary_of_film_1", "director_1");
    fs.add_film("film3", 1999, 80, 1000, "summary_of_film_1", "director_1");
    fs.add_film("film4", 1999, 80, 1000, "summary_of_film_1", "director_1");
    fs.add_film("film5", 1999, 80, 1000, "summary_of_film_1", "director_1");
    fs.add_film("film6", 1999, 80, 1000, "summary_of_film_1", "director_1");
    fs.add_film("film7", 1999, 80, 1000, "summary_of_film_1", "director_1");
    
    Client* client = UserSessionManagement::get_instance()->get_logged_client();
    client->increase_credit(100);
    UserSessionManagement::get_instance()->sign_out();
}