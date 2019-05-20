#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

enum res_type{SUCCESSFUL, ERROR, EMPTY};
#define OK "OK"

class Response
{
public:
    Response(int type, std::string content);
    Response();
    std::string get_content() {return content;};
    friend std::ostream& operator<<(std::ostream&, const Response& respones);
protected:
    int type;
    std::string content;
};

#endif