#include <iostream>


#include "RequestReciever.h"
#include "Request.h"

using namespace std;

int main()
{
    try
    {
        Request my_request = RequestReciever().recieve_request();
        my_request.print_request();
        return 0;
    }
    catch(std::exception* er)
    {
        cout<< er->what() << endl;
    }
}   