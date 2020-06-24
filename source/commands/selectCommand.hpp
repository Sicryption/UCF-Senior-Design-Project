
#pragma once
#include "../commands/commandObject.hpp"

class SelectCommand : public CommandObject
{

public:
    SelectCommand(bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        name="select";
    }

    ~SelectCommand();

    virtual std::string convertToLua()
    {
        return "select_gameobject(" + m_params[0] + ")\n"; 
    }

};