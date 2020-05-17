
#include "userAPI.h"
#include <m3dia.hpp>
#include "m3diaLibCI/console.hpp"
#include "m3diaLibCI/text.hpp"

/**
 *  User API print function
 */
int UserAPI::print(lua_State* L)
{
    if(lua_checkstack(L,1) <= 0)
    {
        std::cerr << "parameter error: not enough parameters to perform 'print'\n";
        return 1;
    }

    
    if(lua_isnumber(L, -1) > 0)
    {
        double number = lua_tonumber(L,-1);
        std::cout<< number << "\n";

    }else{
        const char* text = lua_tostring(L,-1);
        std::cout<< text << "\n";
    }

    return 0;
}