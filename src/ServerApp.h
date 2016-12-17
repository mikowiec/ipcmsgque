#ifndef __SERVERAPP_H__
#define __SERVERAPP_H_

#include <stdio.h>
#include <thread>
#include <iostream>
#include <string>
#include "ServerSocket.h"
#include "Socket.h"

class ServerApp {
  public:
    // server socket init + port value
    ServerApp(int port);

    // start server in thread
    void Run();

  private:
    ServerSocket srv;
};



#endif