#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include "ServerSocket.h"
#include "Socket.h"

ServerSocket::ServerSocket(int port, int queueSize) {
  sockPort = port;
  this->queueSize = queueSize;
  //
  socketId = socket(AF_INET, SOCK_STREAM, 0);
  sockAddr.sin_family = AF_INET;
  sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  sockAddr.sin_port = htonl(sockPort);
  //
  sockLen = sizeof(sockAddr);
}

// Return accepted client descriptor
int ServerSocket::Accept() {
  struct sockaddr_in cliSockAddr;
  int cliSockLen = sizeof(cliSockAddr);
  int cliSockId = ::accept(sockId, (struct sockaddr*)&cliSockAddr, 
                            (socklen_t*)&cliSockLen);
  return cliSockId;
}

int ServerSocket::Bind() {
  return ::bind(sockId, (struct sockaddr *)&sockAddr, sockLen);
}

int ServerSocket::Listen() {
  return ::listen(sockId, queueSize);
}

void ServerSocket::Close() {
  ::close(sockId);
}

ServerSocket::~ServerSocket() {
  Close();
}

