#include <m3dia.hpp>


#include "../userAPI.h"
#include "../util.hpp"   
#include "../m3diaLibCI/text.hpp"
#include "../sceneManager.hpp"
#include "../gameObjects/objects.h"

int UserAPI::move(lua_State* L)
{
    lua_Number t_id = lua_tonumber(L,-1);
    lua_Number x = lua_tonumber(L,-2);
    lua_Number y = lua_tonumber(L,-3);

    Scene* scene = SceneManager::getScene();
    if(scene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }
    GameObject* obj = scene->findObject(t_id);
    if(obj == nullptr)
    {
        Util::PrintLine("Error: couldnt find object \'" + std::to_string(t_id) +"\' in Scene \'" + scene->getSceneName() + "\'");
        return 0;
    }
    
    obj->moveTo(x,y);

    return 0;
}

int make_rectangle(lua_State* L)
{
    lua_Number x = lua_tonumber(L,-1);
    lua_Number y = lua_tonumber(L,-2);

    Scene* scene = SceneManager::getScene();
    if(scene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    int t_id = scene->addObject( new RectangleObject());
    if(t_id == 0)
    {
        Util::PrintLine("Error: could not create Rectangle Object in Scene \'" + scene->getSceneName() + "\'");
        return 0;
    }
    
    lua_pushinteger(L,t_id);
    return 1;
}

int make_circle(lua_State* L) 
{
    lua_Number x = lua_tonumber(L,-1);
    lua_Number y = lua_tonumber(L,-2);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    int t_id = currScene->addObject(new CircleObject()); 
    if(t_id == 0)
    {
        Util::PrintLine("Error: could not create Circle Object in Scene \'" + currScene->getSceneName() + "\'");
        return 0;
    }
    
    lua_pushinteger(L,t_id);
    return 1;
}

int make_paddle(lua_State* L)
{
    return 0;
}
  
// TODO: Revise, no set position, only set x and y.
int set_position(lua_State* L)
{
    lua_Number t_id = lua_tonumber(L,-1);
    lua_Number t_x = lua_tonumber(L,-2);
    lua_Number t_y = lua_tonumber(L,-3);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id) +" in Scene" + currScene->getSceneName() + " \n");
        return 0;
    }

    currObj->setPosition(t_x, t_y);
    
    return 0;
}

int get_x_position(lua_State* L)
{
    lua_Number t_id = lua_tonumber(L,-1);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id ) +" in Scene" + currScene->getSceneName() + " \n");
        return 0;
    }
    //m3d::Vector2f *currentVector = currObj->getPosition();

    lua_pushnumber(L, currObj->getPosition().u);
    return 1;
}
   
int get_y_position(lua_State* L)
{
    lua_Number t_id = lua_tonumber(L,-1);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id) +" in Scene" + currScene->getSceneName() + " \n");
        return 0;
    }
    //m3d::Vector2f *currentVector = currObj->getPosition();

    lua_pushnumber(L,currObj->getPosition().v);
    return 1;
}
   

int rotate(lua_State* L)
{
    lua_Number t_id = lua_tonumber(L,-1);
    lua_Number t_angle = lua_tonumber(L,-2);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id) +" in Scene" + currScene->getSceneName() + " \n");
        return 0;
    }

    currObj->Rotate(t_angle);

    return 0;
}
    
int set_angle(lua_State* L)
{
    lua_Number t_id = lua_tonumber(L,-1);
    lua_Number t_angle = lua_tonumber(L,-2);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id) +" in Scene" + currScene->getSceneName() + " \n");
        return 0;
    }

    currObj->setAngle(t_angle);
    return 0;
}
    
int get_angle(lua_State* L)
{
    lua_Number t_id = lua_tonumber(L,-1);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id) +" in Scene" + currScene->getSceneName() + " \n");
        return 0;
    }

    lua_pushnumber(L, currObj->getAngle());

    return 1;
}
   
// TODO: Design such that x or y = -1, maintains that scale.
int set_scale(lua_State* L)
{
    lua_Number t_id     = lua_tonumber(L,-1);
    lua_Number t_width  = lua_tonumber(L,-2);
    lua_Number t_height = lua_tonumber(L,-3);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id) +" in Scene" + currScene->getSceneName() + " \n");
        return 0;
    }

    currObj->setScale(t_width,t_height);
    return 0;
}
    
    
int set_color(lua_State* L)
{
    lua_Number t_id     = lua_tonumber(L,-1);
    lua_Number t_red  = lua_tonumber(L,-2);
    lua_Number t_green = lua_tonumber(L,-3);
    lua_Number t_blue  = lua_tonumber(L,-2);
    lua_Number t_alpha = lua_tonumber(L,-3);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id) +" in Scene" + currScene->getSceneName() + " \n");

    }
    return 0;
}
   

int delete_object(lua_State* L)
{
    lua_Number t_id = lua_tonumber(L,-1);

    Scene *currScene = SceneManager::getScene();
    if(currScene == nullptr)
    {
        Util::PrintLine("Error: no current scene");
        return 0;
    }

    GameObject *currObj = currScene->findObject(t_id);
    if(currObj == nullptr) 
    {
        Util::PrintLine("Error: could not get specified object " + std::to_string( t_id) +" in Scene" + currScene->getSceneName() + " \n");
        return 0;
    }

    currObj->destroy();
    currObj = nullptr;

    return 0;
}
 
       