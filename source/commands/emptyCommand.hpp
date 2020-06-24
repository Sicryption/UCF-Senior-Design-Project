#pragma once
#include "../commands/commandObject.hpp"

class ElseCommand : public CommandObject
{

public:
    ElseCommand(bool t_lockEdit=false,bool t_lockAdd=false): CommandObject(true, false)
    {
        name="--";
    }

    ~ElseCommand();

    std::vector<std::string> getParamNames() {return {};}


    std::string convertToLua()
    {
        return "--\n"; 
    }

};