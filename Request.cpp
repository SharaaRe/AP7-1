#include <iostream>

#include "Request.h"

#include "Exceptions.h"


using namespace std;



Request::Request(vector <string> raw_request)
{
    map <string, int> methods = {{"GET",GET}, {"PUT", PUT}, {"POST",POST}, {"DELETE",DELETE}};
    string _operator = "?";
    const int COMPLEX_REQ_SIZE = 5;
    
    method = methods[raw_request[0]];
    url = raw_request[1];


    if (raw_request.size() >= COMPLEX_REQ_SIZE)
    {
        // cout << "number of tokens : " << raw_request.size() << endl;
        if ((raw_request.size() - 3 )% 2 == 1)
            throw BadRequest("key and values are not pair");
        for (int i = COMPLEX_REQ_SIZE - 1; i < raw_request.size(); i+=2)
        {
            parameters.insert(pair<string, string>(raw_request[i - 1], raw_request[i]));
        }
    }

}

void Request::print_request()
{
    cout << "method is  " << method << "  urls is:" << url << endl;
    for (map <string, string>::iterator it = parameters.begin(); it != parameters.end(); it++)
    cout << it->first << "   " << it->second << endl;
}

string Request::get_request_param(string key)
{
    string NOT_FOUND = "not found";
    if (parameters.find(key) != parameters.end())
        return parameters[key];
    else
        throw  NotFound("param doesn't exist " + key);
}

int Request::get_method()
{
    return method;
}

std::string Request::get_url()
{
    return url;
}

int Request::number_of_params()
{
    return parameters.size();
}