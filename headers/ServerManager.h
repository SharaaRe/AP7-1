#ifndef SERVER_MANAGER_H
#define SERVER_MANAGER_H

#include "server.hpp"

class ServerManager
{
public:
    ServerManager();
    void run();
private:
    void fake_initializer();
    Server my_server;
};

#endif