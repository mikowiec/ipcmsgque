#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>


class File {
public:
  long long size, time;
  // ok(exist), rd(read), wr(write), ex(execute, dir)
  int isfile, isdir, ok, rd, wr, ex;
  File(const char * pathname);
};

#endif