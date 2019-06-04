#include "ServerManager.h"

#include <iostream>

#include "SignupHandler.h"
#include "LoginHandler.h"
#include "LogoutHandler.h"
#include "HomePageHandler.h"
#include "AddFilmHandler.h"
#include "DeleteFilmsHandler.h"
#include "PageHandlers.h"
#include "ProfileHandler.h"
#include "FilmDetailHandler.h"
#include "BuyHandler.h"
#include "RateHandler.h"
#include "MoneyHandler.h"
#include "UserService.h"
#include "FilmService.h"
#include "Exceptions.h"
#include "CommentHandler.h"
#include "UserSessionManagement.h"

ServerManager::ServerManager()
{
    std::cout << "server manager" << std::endl;

    try{
        std::cout << "something" << std::endl;
        my_server.setNotFoundErrPage("APHTTP/static/404.html"); 
        my_server.get("/", new HomePageHandler("APHTTP/static/mine/PublisherHomePage.html"));   
        my_server.get("/signup", new PageHandlers("APHTTP/static/mine/signup.html"));
        my_server.post("/signup", new SignupHandler());
        my_server.get("/login", new PageHandlers("APHTTP/static/mine/login.html"));
        my_server.post("/login", new LoginHandler());
        my_server.post("/logout", new LogoutHandler());
        my_server.get("/HomePage", new HomePageHandler("APHTTP/static/mine/PublisherHomePage.html"));
        my_server.post("/films", new AddFilmHandler());
        my_server.post("/delete_films", new DeleteFilmsHandler());
        my_server.get("/profile", new ProfileHandler("APHTTP/static/mine/profile.html"));
        my_server.get("/films", new FilmDetailHandler("APHTTP/static/mine/films.html"));
        my_server.post("/buy", new BuyHandler());
        my_server.post("/rate", new RateHandler());
        my_server.post("/money", new MoneyHandler());
        my_server.post("/comment", new CommentHandler());
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
    client->increase_credit(1000);
    UserSessionManagement::get_instance()->sign_out();
}