#include<stdio.h>
#include <string.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

//  defined inii.h here
//  it checkd if init.h is included by any other parent file
//  if not included it includes it
//  init.h will be writteen as INIT_H

#ifndef INIT_H
#define INIT_H
#endif


// ============  Prototype Declaration  ==============
// simple boolean
typedef enum{
  false,true
}bool;

bool checkValidationLayerSupport();

// ===========  Declaration and initialization  ==============
bool DEBUG=true;

const char validationLayers[50][50] ={
    "VK_LAYER_KHRONOS_validation"
};

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
    printf("nuuuuuuuuuuuuu \n");
    if (DEBUG && !checkValidationLayerSupport()) {
    printf("validation layers requested, but not available!\n");
    }
    printf("sgdvhsdgfhjagfhasdf \n");
    VkApplicationInfo appInfo;
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "App";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "YKAN";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;
    printf("hiiiiiiiiiiiiiiiiiii \n");

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

    printf("yassssss\n");
    int instResult=vkCreateInstance(&createInfo, NULL, &instance);

    printf("%d\n",instResult);

    if (instResult != VK_SUCCESS) {
      printf("failed to create instance!\n");}
}
//validation layer (debug)
bool checkValidationLayerSupport(){
    uint32_t layerCount=0;
    vkEnumerateInstanceLayerProperties(&layerCount, NULL);


    VkLayerProperties availableLayers[]={};
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers);


    for (int layer=sizeof(validationLayers);layer>=0;layer-=1) {
    	bool layerFound = false;
    	const char *layerName = validationLayers[layer];

    	printf("Nooooooooooo\n");
    	for (int i=0; i< sizeof(availableLayers)/sizeof(VkLayerProperties); i++) {
        	if (strcmp(layerName, availableLayers[i].layerName) ) {
            		layerFound = true;
           		break;
        	}
    	}

    	if (!layerFound) {
        	return false;
    	}
    }

    printf("Nooooooooooo\n");
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
