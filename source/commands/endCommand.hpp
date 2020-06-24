#pragma once
#include "../commands/commandObject.hpp"

class EndCommand : public CommandObject
{

public:
    EndCommand(bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(t_lockEdit, t_lockAdd)
    {
        name="end";
    }

    ~EndCommand();

    std::vector<std::string> getParamNames() {return {};}

    std::string convertToLua()
    {
        return "end\n"; 
    }

};