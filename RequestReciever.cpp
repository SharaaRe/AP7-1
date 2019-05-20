#include <iostream>

#include "Request.h"

#include "RequestReciever.h"

#include "Exceptions.h"

#include "Utils.h"





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
    vector <string> standard_urls = {SIGN_UP, LOGIN /*, FILMS, PUBLISHED, REPLIES, 
            COMMENTS, FOLLOWERS, MONEY, BUY, RATE, PURCHASED, NOTIFICATION*/};


    if (!valid_token(tokens[0], standard_methods))
        throw  BadRequest("method is not standard");

    
    if (!valid_token(tokens[1], standard_urls))
        throw  NotFound("url is not standard");

    
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