#ifndef __SERVERSOCKET_H__
#define __SERVERSOCKET_H__

#include <unistd.h>
#include <errno.h>

class ClientSocket {
public:
  // 
  ClientSocket(sockId);

  // Close the Socket 
  ~ClientSocket();

  // Close the Socket, 
  void Close();

  // get socket descriptor
  int GetSockId();

  //
  int WriteBuf(const char * msg, int len);

  //
  int WriteBuf(const char * p);

  //
  int RecvBuf();

private:
  // socket descriptor
  int sockId;

  // send buffer via socket
  int wrSock(int sockId, void *buffer, int len);

  // receive buffer via socket
  int rdSock(int sockId, void *buffer, int len);
};


#endif