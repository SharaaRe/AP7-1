#ifndef RATE_HANDLER_H
#define RATE_HANDLER_H

#include "server.hpp"

class RateHandler: public RequestHandler
{
public: 
    Response* callback(Request*);
private:
    int film_id;
    int score;
};

#endif