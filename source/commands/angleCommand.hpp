#pragma once
#include "../commands/commandObject.hpp"

class GetAngleCommand : public CommandObject
{

public:
    GetAngleCommand(std::string t_variable,bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="get angle";
		setParam(0, t_variable);
    }

    ~GetAngleCommand();

    std::vector<std::string> getParamNames() {return { "Variable" };}

    std::string convertToLua()
    {
		return m_params[0] + " = get_angle()\n";
    }

};


class SetAngleCommand : public CommandObject
{

public:
    SetAngleCommand(std::string t_value ="0",bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="set angle";
		setParam(0, t_value);
    }

    ~SetAngleCommand();

    std::vector<std::string> getParamNames() {return {"value"};}

    std::string convertToLua()
    {
        return "set_angle(" + m_params[0] +")\n"; 
    }

};