#include <iostream>

#include "Request.h"

#include "RequestReciever.h"

#include "Exceptions.h"

#include "Utils.h"


using namespace std;

using service::Request;
// using service::Response;

Request RequestReciever::recieve_request()
{
    if (!getline(cin, request_line))
        throw EndOfFile();
    vector <string> tokens = parse_request();
    control_format(tokens);
    return Request(tokens);
}


vector <string> RequestReciever::parse_request()
{
    string delimiters = "   ";
    vector <string> tokens = Utils::split_line(request_line, delimiters);
    if (tokens.size() == 0)
        throw EmptyLine();
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

    vector <string> standard_methods = {GET_, POST_};
    vector <string> standard_urls = {SIGN_UP, LOGIN , LOGOUT, FILMS, PUBLISHED, REPLIES, 
            COMMENTS, FOLLOWERS, MONEY, BUY, RATE, PURCHASED, NOTIFICATION, NOTIFICATION_READ,PUT_FILMS, DELETE_FILMS, DELETE_COMMENTS };

    if (tokens.size() == 0)
        throw EmptyLine();

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