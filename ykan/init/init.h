
//smple boolean
typedef enum{
  false,true
}bool;


//create the window
void initWindow();
//create the vulkan thing
void createInstance();
//init vulkan
void init();
//the update (draw)
void update();
//clean all
void clean();

//run the program
void run(){
  initWindow();
  init();
  update();
  clean();
}
