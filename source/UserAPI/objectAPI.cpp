#include <m3dia.hpp>


#include "../userAPI.h"
#include "../util.hpp"   
#include "../m3diaLibCI/text.hpp"
#include "../sceneManager.hpp"

#define DEFAULT_SIZE 10 
#define DEFAULT_COLOR m3d::Color(255,0,0)



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
    
    return 1;
}

int make_circle(lua_State* L) 
{
    return 0;
}

int make_paddle(lua_State* L)
{
    return 0;
}

int move(lua_State* L)
{
    return 0;
}
   

int set_position(lua_State* L)
{
    return 0;
}

int get_x_position(lua_State* L)
{
    return 0;
}
   
int get_y_position(lua_State* L)
{
    return 0;
}
   

int rotate(lua_State* L)
{
    return 0;
}
    
int set_angle(lua_State* L)
{
    return 0;
}
    
int get_angle(lua_State* L)
{
    return 0;
}
   
// TODO: Design such that x or y = -1, maintains that scale.
int scale(lua_State* L)
{
    return 0;
}
    
int set_scale(lua_State* L)
{
    return 0;
}
    
    
int set_color(lua_State* L)
{
    return 0;
}
   

int delete_object(lua_State* L)
{
    return 0;
}
 
       