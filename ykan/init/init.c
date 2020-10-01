#include<stdio.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

//  defined inii.h here
//  it checkd if init.h is included by any other parent file
//  if not included it includes it
//  init.h will be writteen as INIT_H

#ifndef INIT_H
#define INIT_H
#endif





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

  VkInstanceCreateInfo createInfo = {};
  /*VkInstanceCreateInfo createInfo;
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;*/

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  createInfo.enabledLayerCount = 0;

  int instResult=vkCreateInstance(&createInfo, NULL, &instance);

  printf("%d\n",instResult);

  if (instResult != VK_SUCCESS) {
      printf("failed to create instance!\n");}
}
//validation layer (debug)
int checkValidationLayerSupport(){
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, NULL);

    VkLayerProperties availableLayers[]={};
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers);

    return 0;

    for (const char* layerName : validationLayers) {
    bool layerFound = false;

    for (int i sizeof(availableLayers);i>=0;i-=1;) {
        if (strcmp(layerName, layerProperties.layerName) == 0) {
            layerFound = true;
            break;
        }
    }

    if (!layerFound) {
        return false;
    }
}

return true;
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
  vkDestroyInstance(instance, NULL);

  glfwDestroyWindow(window);
  glfwTerminate();
  printf("cleaned\n");
}
