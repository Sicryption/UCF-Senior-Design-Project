#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C"{
    #include "lua/lua.h"
    #include "lua/lualib.h"
    #include "lua/lauxlib.h"
}

/*  C Closures
*   Lua only accepts C functions which accept 
*   a lua_State parameter and return an integer
*/

int print(lua_State* L)
{
    int number;
    char* string;

    printf("");
    return 0;
}