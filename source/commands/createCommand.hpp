#pragma once
#include "../commands/commandObject.hpp"

class RectangleCommand : public CommandObject
{

public:
    RectangleCommand(std::string t_x = "0", std::string t_x = "0",bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="rect",
        m_params[0] = t_x,
        m_params[1] = t_y
    }

    ~RectangleCommand();

    std::vector<std::string> getParamNames() {return {"x", "y"};}

    std::string convertToLua()
    {
        return "make_rectangle(" + m_params[0] + ", " +  m_params[1] +  ")\n"; 
    }

};

class CircleCommand : public CommandObject
{

public:
    CircleCommand(std::string t_x = "0", std::string t_x = "0",bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="circle",
        m_params[0] = t_x,
        m_params[1] = t_y
    }

    ~CircleCommand();

    std::vector<std::string> getParamNames() {return {"x", "y"};}

    std::string convertToLua()
    {
        return "make_circle(" + m_params[0] + ", " +  m_params[1] +  ")\n"; 
    }

};