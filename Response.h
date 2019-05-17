#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

enum {SUCCESSFUL, ERROR};

class Response
{
public:
    Response(int type, std::string content);
    friend std::ostream& operator<<(std::ostream&, const Response& respones);
protected:
    int type;
    std::string content;
};

#endif