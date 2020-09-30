#include<stdio.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

//Window
GLFWwindow* window;
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;
VkInstance instance;
//Window

//create window
void initWindow(){
  printf("creating the window\n");

  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  window = glfwCreateWindow(WIDTH,HEIGHT, "Vulkan", NULL, NULL);
}


//the VkInstance
void createInstance() {
  VkApplicationInfo appInfo;
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "App";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "YKAN";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo;
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  createInfo.enabledLayerCount = 0;

  if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS) {
      printf("failed to create instance!\n");}
}

//Init vulkan and create window
void init(){
  printf("init\n");

  createInstance();
}

//main loop
void update(){
printf("update\n");
while (!glfwWindowShouldClose(window)) {
       glfwPollEvents();
   }
}

//destroy vk the window basicly clean the memory
void clean(){
printf("clean\n");

glfwDestroyWindow(window);
glfwTerminate();
}



//run the program
void run(){
  initWindow();
  init();
  update();
  clean();
}
