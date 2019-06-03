#include "FilmDetailHandler.h"

#include <sstream>

#include "Exceptions.h"
#include "Utils.h"
#include "FilmService.h"


#define MSG "msg"
#define RATE_MSG_CODE 5
#define RATE_MSG "Rate successfully submitted!"
#define BUY_MSG_CODE 6
#define BUY_MSG "You bought this film successfully!"
#define COMMENT_MSG_CODE 8
#define COMMENT_MSG "Your comment successfully submitted!"
#define NOT_ENOUGH_MONEY_CODE 4
#define NOT_EOUGHT_MONEY "Your credit is less than price of film! Please increase your credit first."

using namespace std;

FilmDetailHandler::FilmDetailHandler(string file_path)
    : TemplateHandler(file_path)
{}

Response* FilmDetailHandler::callback(Request* req)
{
    recoms.clear();
    current_request = req;
    try
    {
        film_id =  Utils::string_integer_value(req->getQueryParam(FILM_ID));
        FilmService film_service();
        film = FilmService().get(film_id);
        recoms = FilmService().get_recommendation_list(film);
        comments = FilmService().get_comments(film_id);
        access = FilmService().client_access(film_id) ? true : false;
        available = film.is_available() ? true : false;
        handle_msg();
        handle_error();
    }
    catch(BadRequest& er)
    {
        throw Server::Exception(er.error());
    }
    catch(NotFound& er)
    {
        throw Server::Exception(er.error());
    }

    return TemplateHandler::callback(req);
}


void FilmDetailHandler::handle_msg()
{
    msg = "";
    string msg_code = current_request->getQueryParam(MSG);
    if (msg_code != KEY_NOT_FOUND)
    {
        try{
            int msg_code_value = Utils::string_integer_value(msg_code);
                    switch (msg_code_value)
            {
            case RATE_MSG_CODE:
                msg = RATE_MSG;
                break;
            case BUY_MSG_CODE:
                msg = BUY_MSG;
                break;
            case COMMENT_MSG_CODE:
                msg = COMMENT_MSG;
                break;
            
            default:
                msg = "";
                break;
            }
                
        }
        catch(BadRequest& er)
        {
            throw Server::Exception("message code is invalid");
        }

    }
}


void FilmDetailHandler::handle_error()
{
    error = "";
    string error_code = current_request->getQueryParam("error");
    if (error_code != KEY_NOT_FOUND)
    {
        try{
            int error_code_value = Utils::string_integer_value(error_code);
            switch (error_code_value)
            {
            case NOT_ENOUGH_MONEY_CODE:
                error = NOT_EOUGHT_MONEY;
                break;
            
            default:
                error = "";
                break;
            }
                
        }
        catch(BadRequest& er)
        {
            throw Server::Exception("error code is invalid");
        }

    }   
}



map <string, string> FilmDetailHandler::handle(Request* req)
{
    map <string, string> context;
    stringstream rate;
    context["msg"] = msg;
    context["error"] = error;
    context["access"] = access? "true" : "false";
    context["available"] = available? "true" : "false";    
    context["name"] = film.get_name();
    context["id" ] = to_string(film.get_id());
    context["name" ] = film.get_name();
    context["price" ] = to_string(film.get_price());
    context["year" ] = to_string(film.get_year());
    context["length" ] = to_string(film.get_length());
    rate.precision(2);
    rate << film.get_rate();
    context["rate" ] = rate.str();
    context["director" ] = film.get_director();

    context["cn"] = comments.size();
    for (int i = 0; i < comments.size(); i++)
    {
        context["comment" + to_string(i)] = comments[i].get_content();
    }

    
    int n = recoms.size() > 4? 4: recoms.size();
    context["n"] = to_string(n);
    for (int i = 0; i < n; i++)
    {
            string index = to_string(i);
            stringstream rate;
            context["id" + index] = to_string(recoms[i].get_id());
            context["name" + index] = recoms[i].get_name();
            context["length" + index] = to_string(recoms[i].get_length());
            context["director" + index] = recoms[i].get_director();
    }

    return context;
}