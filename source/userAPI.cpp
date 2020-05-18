
#include "userAPI.h"
#include "util.hpp"

/**
 *  User API print function
 */
int UserAPI::print_line(lua_State* L)
{
    if(lua_checkstack(L,1) <= 0)
    {
        // TODO: replace with some instruction, displaying the error to the user
        std::cerr << "parameter error: not enough parameters to perform 'print'\n";
        return 1;
    }

    std:: string data;
    if(lua_isnumber(L, -1) > 0)
    {
        double number = lua_tonumber(L,-1);
        data = std::to_string(number);
        Util::getInstance()->PrintLine(data);
    }else{
        const char* text = lua_tostring(L,-1);
        data = std::string(text);
        Util::getInstance()->PrintLine(data);
    }

    return 0;
}