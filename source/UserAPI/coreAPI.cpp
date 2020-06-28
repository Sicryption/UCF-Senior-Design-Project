
#include "../userAPI.hpp"


/**
 *  User API print function, taken from the lua API implementation
 *  @brief
 */
int UserAPI::print_line(lua_State* L)
{   
    int n = lua_gettop(L);  /* number of arguments */
    int i;
    lua_getglobal(L, "tostring");
    for (i=1; i<=n; i++) {
        const char *s;
        size_t l;
        lua_pushvalue(L, -1);  /* function to be called */
        lua_pushvalue(L, i);   /* value to print */
        lua_call(L, 1, 1);
        s = lua_tolstring(L, -1, &l);  /* get result */
        if (s == NULL)
        return luaL_error(L, "'tostring' must return a string to 'print'");
        if (i>1) lua_writestring("\t", 1);
        lua_writestring(s, l);
        lua_pop(L, 1);  /* pop result */
    }
    lua_writeline();
    return 0;
}


int UserAPI::print(lua_State* L)
{    
    const char *s;
    size_t l;

    //   Convert evaluated parameter to string
    s = lua_tolstring(L, -1, &l);  
    if (s == NULL)
    {
        Util::getInstance()->PrintLine("'tostring' must return a string to 'print'");
        return luaL_error(L, "'tostring' must return a string to 'print'");
    }

    //  Write to Console
    Util::Print(s);

    // Number of results returned
    return 0; 
}  





