#pragma once
#include <stdlib.h>
#include <string>
#include <vector>

#include <m3dia.hpp>
#include "../m3diaLibCI/sprite.hpp"
#include "../resources.h"
#include "../gameManager.hpp"

#define MAX_PARAMS 3
#define COM_PADDING 3
#define COM_SPACING 5
#define COM_TEXT_COLOR m3d::Color(0,0,0)

class CommandObject //: public Drawable 
{

protected:
    std::string m_name;
    bool m_isEditLocked;
    bool m_isAddLocked;
    std::string m_params[MAX_PARAMS];
    m3dCI::Sprite m_background;
	m3dCI::Text* m_text[MAX_PARAMS + 1] = { nullptr, nullptr, nullptr, nullptr };

public:
    CommandObject(bool t_lockEdit = false,bool t_lockAdd = false)
    {
        m_name="";
        m_isEditLocked = t_lockEdit;
        m_isAddLocked = t_lockAdd;
        m_background = m3dCI::Sprite( *ResourceManager::getSprite("command_background.png"));
        m_text[0] = new m3dCI::Text(m_name);
    }

    ~CommandObject(){}

    virtual std::vector<std::string> getParamNames() 
    { 
        return  {"error"};
    }
    
    void setParams(std::string t_params[MAX_PARAMS])
    {
        for (int i = 0; i < MAX_PARAMS; i++)
        {
            m_params[i] = t_params[i];
        }
    }

    virtual std::string convertToLua()
    {
        return "";
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

    virtual void draw(double t_x, double t_y, m3d::RenderContext t_context)
    {
        m3d::Screen* scr = GameManager::getScreen();
        unsigned short int paramCount = getParamNames().size();

		m_background.setPosition(t_x, t_y);
		m_background.draw(t_context);

        m_text[0]->setText(m_name);
        m_text[0]->setColor(COM_TEXT_COLOR);
        m_text[0]->setFontWeight(0.6f);
		m_text[0]->setFontSize(0.6f);

		m_text[0]->setPosition(t_x + COM_PADDING, t_y + COM_PADDING);
		m_text[0]->draw(t_context);

        int t_yCursor = t_y + COM_PADDING;
        int t_xCursor = m_text[0]->getWidth() + COM_PADDING + (2 * COM_SPACING);
        int t_paramStartX = t_xCursor - COM_SPACING;

        for (unsigned int i = 1; i < paramCount; i++)
        {
            if(m_text[i] != nullptr)
            {
				m_text[i]->setPosition(t_xCursor, t_yCursor);
                m_text[i]->draw(t_context);
                t_xCursor += m_text[i - 1]->getWidth() + COM_SPACING;
            }
        }
    }


};

