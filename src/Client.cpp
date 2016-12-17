
#include "Client.h"

void SockWorker(int ClientSocket) {
  //
  ClientSocket cli(ClientSocket);
  SockReq req(cli);
  SockResp resp(req);

  // client wait message "STOP" to finish working cycle
  while(req.IsConnected()) {
    int cmd = resp.getCommand();
    if(cmd == CMD_STOP) {
      std::cout << std::endl << "command STOP. Client session completed." << std::endl;
      return;
    }

  }
  std::cout << std::endl << "Connection lost" << std::endl;

}