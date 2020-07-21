#pragma once
#include "../commands/commandObject.hpp"

class GetXCommand : public CommandObject
{

public:
    GetXCommand(std::string t_variable,bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="get x";
		setParam(0, t_variable);
    }

    ~GetXCommand();

    std::vector<std::string> getParamNames() {return { "Variable"};}

    std::string convertToLua()
    {
        return m_params[0] + " = get_x()\n"; 
    }

};

class GetYCommand : public CommandObject
{

public:
    GetYCommand(std::string t_variable,bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="get y";
		setParam(0, t_variable);
    }

    ~GetYCommand();

    std::vector<std::string> getParamNames() {return {"Variable"};}

    std::string convertToLua()
    {
        return m_params[0] + " = get_y()\n"; 
    }

};

class SetXCommand : public CommandObject
{

public:
    SetXCommand(std::string t_value,bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="set x";
		setParam(0, t_value);
    }

    ~SetXCommand();

    std::vector<std::string> getParamNames() {return {"value"};}

    std::string convertToLua()
    {
        return "set_x(current_object," + m_params[0] +")\n"; 
    }

};

class SetYCommand : public CommandObject
{

public:
    SetYCommand(std::string t_value, bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="set y";
		setParam(0, t_value);
    }

    ~SetYCommand();

    std::vector<std::string> getParamNames() {return {"value"};}

    std::string convertToLua()
    {
        return "set_y( current_object," + m_params[0] +")\n"; 
    }

};