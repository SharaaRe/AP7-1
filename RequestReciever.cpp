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
    vector <string> tokens = Utils::split_line(request_line, delimiters);
    int operator_index = Utils::find("?", tokens);
    if (operator_index!= NOT_FOUND)
        tokens = Utils::merge_tokens(1, operator_index - 1, tokens);
}








void RequestReciever::control_format(vector <string> tokens)
{

    vector <string> standard_methods = {GET, PUT, POST, DELETE};
    vector <string> standard_urls = {SIGN_UP, FILMS, PUBLISHED, REPLIES, 
            COMMENTS, FOLLOWERS, MONEY, BUY, RATE, PURCHASED};


    if (!valid_token(tokens[0], standard_methods))
        throw new BadRequest();
    
    if (!valid_token(tokens[1], standard_urls))
        throw new NotFound();

    


}


bool RequestReciever::valid_token(string token, vector <string> valid_tokens)
{
    for (int i = 0; i < valid_tokens.size(); i++)
    {
        if (token == valid_tokens[i])
            return true;
    }
    return false;
}