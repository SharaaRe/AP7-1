#include "UTflixService.h"

#include <iostream>


using namespace std;

void UTflixService::run()
{
    while (true)
    {
        try
        {
            current_request = input.recieve_request();
            controller_manager.run_controller(&current_request);
            current_response =  controller_manager.get_response();
        }
        catch(EndOfFile)
        {
            break;
        }
        catch(EmptyLine& em)
        {
            continue;
        }
        catch(Exception& er)
        {
            current_response = Response(ERROR, er.what());
        }
        cout << current_response;
    }
}