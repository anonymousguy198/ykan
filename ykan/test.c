#include <stdio.h>
#include "class.h"

int main(int argc, char const *argv[]) {

  struct test t;

  initClass(&t);
<<<<<<< HEAD
=======

  // used &t so that this variable is initialized
  // earlier a copy of t was initialized and it wasnt accessible here
  // so you got weird numbers on printing
  

>>>>>>> ff5d57db6804f412334a3898b225a8f01e3e2c80

  printf("%d,\n",t.i);

  t.fn(1,2);

  return 0;
}
