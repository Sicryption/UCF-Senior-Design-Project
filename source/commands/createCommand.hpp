#pragma once
#include "../commands/commandObject.hpp"

class RectangleCommand : public CommandObject
{

public:
    RectangleCommand(std::string t_x = "0", std::string t_y = "0",bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="rect";
        m_params[0] = t_x;
        m_params[1] = t_y;
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
    CircleCommand(std::string t_x = "0", std::string t_y = "0",bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="circle";
        m_params[0] = t_x;
        m_params[1] = t_y;
    }

    ~CircleCommand();

    std::vector<std::string> getParamNames() {return {"x", "y"};}

    std::string convertToLua()
    {
        return "make_circle(" + m_params[0] + ", " +  m_params[1] +  ")\n"; 
    }

};

class TextCommand : public CommandObject
{

public:
    TextCommand(std::string t_x = "0", std::string t_y = "0",std::string t_text = "text",bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="text";
        m_params[0] = t_x;
        m_params[1] = t_y;
        m_params[2] = t_text;

    }

    ~TextCommand();

    std::vector<std::string> getParamNames() {return {"text"};}

    std::string convertToLua()
    {
        return "make_text(" + m_params[0] + ")\n"; 
    }

};

class VarCommand : public CommandObject
{

public:
    VarCommand(std::string t_name = "text",bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="var";
        m_params[0] = t_name;

    }

    ~VarCommand();

    std::vector<std::string> getParamNames() {return {"text"};}

    std::string convertToLua()
    {
        return  m_params[0] + " = 0\n"; 
    }

};