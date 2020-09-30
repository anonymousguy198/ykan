# ykan

**YKAN** is a game engine writen in c for game and graphics development.
it makes it easy to write *Vulkan* apps easier without needing to struggle
with vulkan's long setup process.

### what ykan has

**done**


* window creation

**todo**


* vk init
* support for android and vr
* raytracing
* main website
* docs
* drawing
* shaders
* collision
* 2d support
* 3d support
* 2D and 3D collision
* 2D and 3D physics engine
* editor (the engine will not work like unity, unreal or godot
  is not an engine with gui but will have some tools for helping build levels
  in 2D and 3D)
  * 2D tileset editor
  * objects (player pos enemy spawn)
  * tile collision
  * 3D level editor (that also has objects)

### basic code

To make a ykan project you need to setup some things.

1. install YKAN
2. insatll glfw3

now let's grt to the code (note this code i written in c but ykan for the reason
that is made in c libs that make other languages use ykan are easy to make)

```c
//import YKAN
#include <ykan.h>

//the update function
int update(){
  return,0
}


//the main function
int main(int argc, char const *argv[]) {

  //the main struct
  ykApp app;

  //setup the struct
  app.name='app';
  app.createWindow=YkcreateWin;
  app.init=YkinitVk;
  //in this way you can create custom init functions for the best performance
  app.update=update;
  app.run=YkRun;

  //create window and init vulkan
  app.createWindow(420,500,"my app");
  app.init();

  //update (draw function)
  app.update();


  //the last line shoud be the run
  app.run();
  return 0;
}

```

### this project is open source
please help me make this engine
if you find some spelling mistakes or you want to
help me with the engine development contact me
twitter @arydev_7
telegram @arydev
email arydev7@gmail.com
