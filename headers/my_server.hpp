#ifndef __MY_SERVER__
#define __MY_SERVER__

#include "server.hpp"

class MyServer : public Server {
public:
  MyServer(int port = 5000);
};

#endif
