#pragma once
#include <stdlib.h>
#include <string>
#include <vector>

#include <m3dia.hpp>
#include "../m3diaLibCI/sprite.hpp"
#include "../resources.h"
#include "../gameManager.hpp"

#define MAX_PARAMS 3

class CommandObject //: public Drawable 
{

protected:
    std::string m_name;
    bool m_isEditLocked;
    bool m_isAddLocked;
    std::string m_params[MAX_PARAMS];
    m3dCI::Sprite m_background;

public:
    CommandObject(bool t_lockEdit = false,bool t_lockAdd = false)
    {
        m_name="";
        m_isEditLocked = t_lockEdit;
        m_isAddLocked = t_lockAdd;
        m_background = m3dCI::Sprite( *ResourceManager::getSprite("command_background.png"));
    }

    ~CommandObject(){}

    virtual std::vector<std::string> getParamNames() 
    { 
        return  {"error"};
    }
    {
        for (int i = 0; i < MAX_PARAMS; i++)
        {

    virtual std::string convertToLua()
    {
        return "";
    }

    virtual void draw(m3d::RenderContext t_context)
    {
        m3d::Screen* scr = GameManager::getScreen();
        m_background.draw(t_context);
       
    }

    static std::string ConvertBulk(std::vector<CommandObject*> t_list)
    {
        std::string chunk;
        for (CommandObject* cmd : t_list)
        {
            chunk.append(cmd->convertToLua());
        }
        return chunk;
    }

};

