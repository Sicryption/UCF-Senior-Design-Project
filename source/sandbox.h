#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h> 

extern "C"{
    #include <lua/lua.h>
    #include <lua/lualib.h>
    #include <lua/lauxlib.h>
}

int luaPrint(lua_State* L)
{
    const char* text = lua_tolstring(L,-1,NULL);
        printf("%s\n",text);

        return 1;
}

lua_State* initializeSandbox()
{
    lua_State *L = luaL_newstate();

    /*
    auto luaPrint = [](lua_State* L) -> int
    {
       
        const char* text = lua_tolstring(L,-1,NULL);
        printf("%s\n",text);

        return 1;
    };
    */

    lua_pushcclosure(L, (luaPrint), 0);
    lua_setglobal(L, "print");

    return L;
}