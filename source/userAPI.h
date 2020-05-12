#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lua/lua.hpp"

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