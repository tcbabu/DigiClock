#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *Rundigiclock(void *);
int main(void) {
// kgStartX(NULL) //can be used;
  if(fork()!= 0) return 1;
  Rundigiclock(NULL);
//  kgCloseX(); //canbe used
  return 1;
}
