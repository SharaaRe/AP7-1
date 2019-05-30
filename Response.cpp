#include "Response.h"

using namespace std;
using service::Response;

Response::Response(int _type, string _content)
    :type(_type), content(_content)
{}

Response::Response()
    :type(EMPTY)
{}



// ostream& operator<<(ostream& out, const service::Response& response)
// {
//     out << response.get_content();
//     return out;
// }