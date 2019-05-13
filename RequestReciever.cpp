#include <iostream>

#include "RequestReciever.h"

#include "Exceptions.h"

#include "Utils.h"

#define GET "GET"
#define PUT "PUT"
#define DELETE "DELETE"
#define POST "POST"

#define SIGN_UP "signup"
#define LOGIN "login"
#define FILMS "films"
#define PUBLISHED "published"
#define REPLIES "replies"
#define COMMENTS "comments"
#define FOLLOWERS "followers"
#define MONEY "money"
#define BUY "buy"
#define RATE "rate"
#define PURCHASED "purchased"
#define NOTIFICATION //what the fuck :D



using namespace std;

Request RequestReciever::recieve_request()
{
    getline(cin, request_line);

    vector <string> tokens = parse_request();
    control_format(tokens);
    
}


//these two must be in utils




vector <string> RequestReciever::parse_request()
{
    string delimiters = "   ";
    Utils util();
    vector <string> tokens = util.split_line(request_line, delimiters);
    int operator_index = util.find()
}








void RequestReciever::control_format(vector <string> tokens)
{

    vector <string> standard_methods = {GET, PUT, POST, DELETE};
    vector <string> standard_urls = {#define SIGN_UP, FILMS, PUBLISHED, REPLIES, 
            COMMENTS, FOLLOWERS, MONEY, BUY, RATE, PURCHASED};

    int seprator_index = find(_operator, raw_request);
        

    if (!valid_token(tokens[0], standard_methods))
        throw new BadRequest();
    
    if (!valid_token(tokens[1], standard_urls))
        throw new NotFound();

    


}


bool RequestReciever::valid_token(std::string token, std::vector <std::string> valid_tokens)
{
    for (int i = 0; i < valid_tokens.size(); i++)
    {
        if (tokens[0] == valid_tokens[i])
            return true;
    }
    return false;
}