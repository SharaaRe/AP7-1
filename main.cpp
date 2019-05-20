#include <iostream>


#include "RequestReciever.h"
#include "ControllerManager.h"
#include "Request.h"
#include "Response.h"
#include "Exceptions.h"

#include "DataBase.h"

using namespace std;

int main()
{
    while (true)
    {
        try
        {
            Request my_request = RequestReciever().recieve_request();
            my_request.print_request();
            ControllerManager controller_manager;
            cout << "main line 19" << endl;
            controller_manager.run_controller(&my_request);
            cout << "main line 21" << endl;    
            // cout << controller_manager.get_response().get_content() << endl;
        }
        catch(Exception& er)
        {
            #ifdef DEBUG
                cout<< er.error() << endl;            
            #endif
            
            #ifndef DEBUG 
                cout << er.what() << endl;
            #endif

        }
    }

    return 0;
}   