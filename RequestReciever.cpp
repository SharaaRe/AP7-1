#include <iostream>

#include "Request.h"

#include "RequestReciever.h"

#include "Exceptions.h"

#include "Utils.h"

#define GET_ "GET"
#define PUT_ "PUT"
#define DELETE_ "DELETE"
#define POST_ "POST"

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
    
    return Request(tokens);
    

}


//these two must be in utils




vector <string> RequestReciever::parse_request()
{
    string delimiters = "   ";
    vector <string> tokens = Utils::split_line(request_line, delimiters);
    int operator_index = Utils::find("?", tokens);

    int to;
    if (operator_index!= NOT_FOUND)
        to = operator_index - 1;
    else
        to = tokens.size() - 1;
    tokens = Utils::merge_tokens(1, to, tokens);


    return tokens;
}








void RequestReciever::control_format(vector <string> tokens)
{

    vector <string> standard_methods = {GET_, PUT_, POST_, DELETE_};
    vector <string> standard_urls = {SIGN_UP, FILMS, PUBLISHED, REPLIES, 
            COMMENTS, FOLLOWERS, MONEY, BUY, RATE, PURCHASED};


    if (!valid_token(tokens[0], standard_methods))
        throw new BadRequest(95);

    
    if (!valid_token(tokens[1], standard_urls))
        throw new NotFound(100);

    
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