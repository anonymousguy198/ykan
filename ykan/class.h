#include <stdio.h>

//CLASSES in C


//smple boolean
typedef enum{
  false,true
}bool;


//function should have same datatype as function pointer
//return type of testfn was int which caused error

void testfn(int a,int b){
  printf("a is %d b is %d\n",a,b);
}

struct test{
  int i;
  void (*fn)(int,int);

};

bool initClass(struct test *cl){
<<<<<<< HEAD
  cl->i=10;
  cl->fn=&testfn;
=======
  cl->i=10;                 // use -> when accessing variables of a pointer
  cl->fn=testfn;
>>>>>>> ff5d57db6804f412334a3898b225a8f01e3e2c80
  return true;
}
