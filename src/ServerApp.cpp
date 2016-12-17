
#include "Server.h"

ServerApp::ServerApp(int port) {
  srv = port;
}


void ServerApp::Run() {
  int socketId;
  srv.bind();
  srv.listen();
  std::cout << std::endl << "Server run" << std::endl;
  //
  while(1) {
    socketId = srv.Accept();
    //
    std::thread t(SockWorker, socketId);
    t.detach();
  }


}