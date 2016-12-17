#include <stdlib.h>
#include <string.h>
#include "Server.h"
#include "File.h"



#define DEF_PORT 80

int main(int argc, char ** argv) {
  int port;
  // define communication port via command line
  if(argc == 2) sscanf(argv[1], "%d", &port);
    else port = DEF_PORT;

  // server start
  ServerApp srv(port);
  srv.run();

}

