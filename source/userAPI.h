#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <utility>

#include "lua/lua.hpp"


/**
 *  A namespace defining the functions bound to a Lua Sandbox
 *  Any function to become a user functions must be a C Closure, returning an int and accepting a lua_State*.
 *  enabled functions must be added to the enabledFunctions array manually
 */
namespace UserAPI
{
    
    int print(lua_State* L);  

    
}
