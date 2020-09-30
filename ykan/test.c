#include <stdio.h>
#include "class.h"

int main(int argc, char const *argv[]) {

  struct test t;

  initClass(t);

  printf("%d,\n",t.i);

  t.fn(1,2);

  return 0;
}
