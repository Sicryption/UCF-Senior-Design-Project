#include "resources.h"


ResourceManager* ResourceManager::_instance = NULL;

ResourceManager* ResourceManager::getInstance()
{
    if(_instance == NULL)
    {
        _instance = new ResourceManager();
    }
    return _instance;
}

void* ResourceManager::readAssetFile(std::string path)
{
    void* asset = NULL;
    

    return asset;

}