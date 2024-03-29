#include "VulkanManager.hpp"

using namespace Dragon;

Dragon::VulkanManager::VulkanManager() {
     VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &Dragon::instance) != VK_SUCCESS)
        std::cerr << "Issue with vkCreateInstance" << std::endl;

    if(gm->getBestDevice() == VK_NULL_HANDLE)
        std::cerr << "No Physical Device found." << std::endl;
}

Dragon::VulkanManager::~VulkanManager() {
    vkDestroyInstance(Dragon::instance, nullptr);
    delete gm;
}