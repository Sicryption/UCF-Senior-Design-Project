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
    _instance->_hashmap = new std::map<std::string, void*>();
    
    try
    {
        void* buffer = readFile("gfx/error.png");
        _instance->_error = new m3d::Texture();
        _instance->_error->loadFromBuffer(buffer);
        
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

void* ResourceManager::readFile(std::string path)
{
    char* buffer;
    
    FILE* fp = fopen( path.c_str(), "rb");
    if(fp == NULL){
        throw std::invalid_argument("unable to access file '" + path + "'");
    }

   
    fseek(fp,0L, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    buffer = (char*)calloc(size, sizeof(char));
    fread(buffer,sizeof(char),size,fp);
    fclose(fp);


    return (void*)buffer;
}

void* load(std::string id, std::string path)
{
    void* mem = NULL;
    try
    {
        mem = readFile(id,path);
    }
    catch(const std::exception& e)
    {
        Util::getInstance()->PrintLine( e.what() );
        mem = NULL;
    }

    (*_hashmap)[id] = mem;
    return mem;
}

m3d::Texture* ResourceManager::loadTexture(std::string id, std::string path)
{
    m3d::Texture* texture = new m3d::Texture();
  
    try
    {
        if( texture->loadFromFile(path) == false)
        {
            Util::getInstance()->PrintLine("failed to load from file " + (TEXTURE_PATH + path));
            return NULL;
        }
    }
    catch(const std::exception& e)
    {
        Util::getInstance()->PrintLine(e.what());
        return NULL;
    }

    (*_hashmap)[id] = texture;
    return texture;

}

//  TODO: test returns when key is not found
m3d::Texture* ResourceManager::getTexture(std::string id)
{
    m3d::Texture* tex;
    
    tex = static_cast<m3d::Texture*>( (*_hashmap)[id] ); 
    
    return tex;
}

