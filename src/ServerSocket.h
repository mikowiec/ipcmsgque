#ifndef __SERVERSOCKET_H__
#define __SERVERSOCKET_H__


#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "Socket.h"

Class ServerSocket {
public:

  // Create a new Socket object
  ServerSocket(int port, int queueSize = 8);

  // Close the Socket
  ~ServerSocket ();

  // Bind the socket to a defined address
  int Bind();

  // Call accept to get a new connection
  int Accept();

  // Start listening for new connections
  int Listen();

  int GetPort();

  // Close the Socket, 
  void Close();

private:
  // socket descriptor
  int sockId;

  // socket port
  int sockPort;

  // socket address
  struct sockaddr_in sockAddr;

  // socket address length
  int sockLen;

  // queue size
  int queueSize;
};

#endif