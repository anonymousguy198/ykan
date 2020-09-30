#include <stdio.h>

//CLASSES in C


//smple boolean
typedef enum{
  false,true
}bool;

int testfn(int a,int b){
  printf("a is %d b is %d\n",a,b);
  return 0;
}

struct test{
  int i;
  void (*fn)(int,int);

};

bool initClass(struct test cl){
  cl.i=10;
  cl.fn=testfn;
  return true;
}
