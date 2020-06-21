#include <m3dia.hpp>

#include "userAPI.h"
#include "managers/sceneManager.hpp"
#include "objects/objects.h"
#include "scenes/scene.hpp"
#include "managers/util.hpp"   
#include "m3diaLibCI/text.hpp"


/**
 * @brief
 * @returns
 */
int UserAPI::create_rectangle(lua_State* L)
{
    Scene* curr = SceneManager::getScene(); 
    if(curr == nullptr)
    {
        //  TODO: Error, return 0 to stack
        lua_pushinteger(L,0);
    }
    
    RectangleObject* rect = new RectangleObject();
    unsigned int id = curr->addObject(rect);
    lua_pushinteger(L,id);

    return 1;
}

int UserAPI::create_circle(lua_State* L)
{
    return 1;
}

int UserAPI::create_paddle(lua_State* L)
{
    return 1;
}

int UserAPI::create_avatar(lua_State* L)
{
    return 1;
}