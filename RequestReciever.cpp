#include "RequestReciever.h"

#include "Exeptions.h"

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

void RequestReciever::read_request()
{
    getline(cin, request_line);
}


//these two must be in utils


bool is_in_string(char character, string checkString)
{
    for (int i = 0; i < checkString.length(); i++)
        if (character == checkString[i])
            return true;
    return false;
}

vector <string> RequestReciever::parse_request()
{
    string delimiters = "   ";
    Tokens tokens;
    int start = 0; int length = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (is_in_string(line[i], delimiters))
        {
            if (length > 0)
                tokens.push_back(line.substr(start, length));

            start = i+1;
            length = 0;
        } 
        else
            length++;
    }
    tokens.push_back(line.substr(start, length));
    return tokens;  
}


void RequestReciever::control_format(vector <string> tokens)
{
    vector <string> standard_methods = {GET, PUT, POST, DELETE};
    vector <string> standard_urls = {#define SIGN_UP, FILMS, PUBLISHED, REPLIES, 
            COMMENTS, FOLLOWERS, MONEY, BUY, RATE, PURCHASED};

    if (!valid_token(tokens[0], standard_methods))
        throw new BadRequest();
    
    if(!valid_token(tokens[1], standard_urls))
        throw new NotFound();

}


bool RequestReciever::valid_token(std::string token, std::vector <std::string> valid_tokens)
{
    for (int i = 0; i < standard_methods.size(); i++)
    {
        if (tokens[0] == standard_methods[i])
            return true;
    }
    return false;
}