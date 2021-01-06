#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main (int argc, char *argv[]) {
  if(argc==1) {
    write(1, "Please specify how long you want to sleep", 41);
  } else {
    int c = atoi(argv[1]);
    sleep(c);
  }
  exit(0);
}

