#include "File.h"

File::File(const char * pathname) {
  struct stat statbuf;

  size = time = 0;
  isfile = isdir = 0;
  ok = rd = wr = ex = 0;
 
  if(access(pathname, F_OK) == 0) ok = 1;
   else return;

  stat(pathname, &statbuf);
  if(S_ISREG(statbuf.st_mode)) isfile = 1;
  if(S_ISDIR(statbuf.st_mode)) isdir = 1;
  size = statbuf.st_size;
  time = statbuf.st_mtime;

  if(access(pathname, R_OK) == 0) rd = 1;
  if(access(pathname, W_OK) == 0) wr = 1;
  if(access(pathname, X_OK) == 0) ex = 1;
}