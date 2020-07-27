#pragma once
#include "../commands/commandObject.hpp"

class ScaleCommand : public CommandObject
{

public:
    // TODO: Design such that x or y = -1, maintains that scale.
    ScaleCommand(std::string t_x , std::string t_y , bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="scale";
		setParam(0, t_x);
		setParam(1, t_y);
    }

    ~ScaleCommand();

    std::vector<std::string> getParamNames() {return {"x scale", "y scale"};}

    std::string convertToLua()
    {
        return "set_scale(current_object," + m_params[0] + "," + m_params[1] + ")\n"; 
    }

};

class Scale_X_Command : public CommandObject
{

public:
    // TODO: Design such that x or y = -1, maintains that scale.
    Scale_X_Command(std::string t_x = "1", bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="scale x";
		setParam(0, t_x);
    }

    ~Scale_X_Command();

    std::vector<std::string> getParamNames() {return {"x scale"};}

    std::string convertToLua()
    {
        return "set_scale(current_object," + m_params[0] + ", -1)\n"; 
    }

};

class Scale_Y_Command : public CommandObject
{

public:
    // TODO: Design such that x or y = -1, maintains that scale.
    Scale_Y_Command(std::string t_y = "1", bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="scale y";
		setParam(0, t_y);
    }

    ~Scale_Y_Command();

    std::vector<std::string> getParamNames() {return {"y scale"};}

    std::string convertToLua()
    {
        return "set_scale(current_object, -1," + m_params[0] + ")\n"; 
    }

};

class Get_ScaleXCommand : public CommandObject
{

public:
    // TODO: Design such that x or y = -1, maintains that scale.
    Get_ScaleXCommand(std::string t_varName = "var", bool t_lockEdit=false, bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="get x scale";
		setParam(0, t_varName);

    }

    ~Get_ScaleXCommand();

    std::vector<std::string> getParamNames() {return {"Variable"};}

    std::string convertToLua()
    {
        return "get_x_scale(current_object, " + m_params[0] + ")\n"; 
    }

};

class Get_ScaleYCommand : public CommandObject
{

public:
    // TODO: Design such that x or y = -1, maintains that scale.
    Get_ScaleYCommand(std::string t_varName = "var", bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        m_name="get y scale";
		setParam(0, t_varName);
    }

    ~Get_ScaleYCommand();

    std::vector<std::string> getParamNames() {return {"Variable"};}

    std::string convertToLua()
    {
        return "get_y_scale(current_object, " + m_params[0] + ")\n"; 
    }

};




