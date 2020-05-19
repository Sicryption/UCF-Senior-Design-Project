#pragma once
#include <iostream>
#include <stdlib.h> 
#include <map>

#include <m3dia.hpp>

#define ROMFS_PATH      "romfs:/"
#define TEXTURE_PATH    "romfs:/gfx"
#define AUDIO_PATH      "romfs:/sfx"
#define TEXTURE_EXT {"png","jpg","bmp"}


/** @class ResourceManager
 *  Singleton Resource Managment class.
 *  Load and unload resources from the ROM file system to memory
 */
class ResourceManager
{
private:
    
    ResourceManager();
    ~ResourceManager();
    
    static ResourceManager* _instance;
    static std::map<std::string, void*> _hashmap;
    
    static ResourceManager* getInstance();

public:

    /**
     *  @brief Reads a File from the ROM file system, but does not load it into the resource manager
     *  @param path file path relative to the rom file system
     *  @returns pointer to the retrieved file data
     */
    static void* readAssetFile(std::string);

    /**
     *  @brief Loads a Texture Asset
     *  Loads a Texture asset from the ROM file system into the Resource Manager
     *  @param id unique identifier of the asset
     *  @param path file path relative to the rom file system
     *  @returns pointer to the loaded resource
     */
    static m3d::Texture* LoadTexture(std::string, std::string);

    /**
     *  @brief Loads a Sound asset
     *  Loads a Sound asset from the ROM file system into the Resource Manager
     *  @param id unique identifier of the asset
     *  @param path file path relative to the rom file system
     *  @returns pointer to the loaded resource
     */
    static m3d::Sound* LoadSound(std::string, std::string);

    /**
     *  Loads an asset from the ROM file system into the Resource Manager
     *  @param id unique identifier of the asset
     *  @param path file path relative to the rom file system
     *  @returns pointer to the loaded resource
     */
    static void* Load(std::string, std::string);

    /**
     *  Unloads all assets from the Resource manager
     */
    static void UnloadAll();

    /**
     *  Unloads an asset from the Resource Manager
     *  @param path unique identifier of the asset
     */
    static void Unload(std::string);


};