#ifndef SERVER_MANAGER_H
#define SERVER_MANAGER_H

#include "APHTTP/server/server.hpp"

class ServerManager
{
public:
    ServerManager();
    void run();
private:
    Server my_server;
};

#endif