// #include "UTflixService.h"
#include "ServerManager.h"

#include <iostream>

int main()
{
    std::cout << "main" << std::endl;
    // UTflixService().run();
    ServerManager().run();
    
    return 0;
}