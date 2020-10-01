
//vulkan validation layers
/*const char validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif*/

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
