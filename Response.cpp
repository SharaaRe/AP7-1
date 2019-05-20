#include "Response.h"

using namespace std;

Response::Response(int _type, string _content)
    :type(_type), content(_content)
{}

Response::Response()
    :type(EMPTY)
{}



ostream& operator<<(ostream& out, const Response& responese)
{
    out << responese.content;
    return out;
}