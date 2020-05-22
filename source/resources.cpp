#include "resources.h"


ResourceManager* ResourceManager::_instance = NULL;
std::map<std::string, void*>* ResourceManager::_hashmap = NULL;
m3d::Texture* ResourceManager::_error = NULL;

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
    
}

void ResourceManager::initialize()
{
    //  If no instance exists, construct one
    if(_instance == NULL)
    {
        _instance = new ResourceManager();
    }

    //  set all fields and stores;
    if(_hashmap != NULL){
        //UnloadAll();
    }
    _hashmap = new std::map<std::string, void*>();
    
    try
    {
        void* buffer = readAssetFile("gfx/error.bmp");
        _error = new m3d::Texture();
        _error->loadFromBuffer(buffer);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return;

}

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
    char* buffer;
    
    std::string fullPath = ROMFS_PATH + path;
    
    FILE* fp = fopen( fullPath.c_str(), "rb");
    if(fp == NULL){
        throw std::invalid_argument("unable to access file '" + fullPath + "'");
    }

   
    fseek(fp,0L, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    buffer = (char*)calloc(size, sizeof(char));
    fread(buffer,sizeof(char),size,fp);
    fclose(fp);


    return (void*)buffer;
}

m3d::Texture* ResourceManager::loadTexture(std::string id, std::string path)
{
    void* mem = NULL;
    bool loaded = false;
    m3d::Texture* texture = new m3d::Texture();

    try
    {
        mem = readAssetFile( TEXTURE_PATH + path);
        loaded = texture->loadFromBuffer(mem);
    }
    catch(const std::exception& e)
    {
        throw e;
    }
    

    if(!loaded)
    {
        throw std::invalid_argument("could not convert file to Texture");
    }

    _hashmap->insert_or_assign(id,texture);
    return texture;

}

m3d::Texture* ResourceManager::getTexture(std::string id)
{
    m3d::Texture* tex;
    try
    {
        tex = _hashmap->at(id);        
    }
    catch(const std::out_of_range& e)
    {
        tex = NULL;
    }
    
    return tex;
}

