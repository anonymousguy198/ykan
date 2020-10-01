#include <stdio.h>
#include "class.h"

int main(int argc, char const *argv[]) {

  struct test t;

  initClass(&t);

  // used &t so that this variable is initialized
  // earlier a copy of t was initialized and it wasnt accessible here
  // so you got weird numbers on printing
  


  printf("%d,\n",t.i);

  t.fn(1,2);

  return 0;
}
