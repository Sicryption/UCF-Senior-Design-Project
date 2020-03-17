#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C"{
    #include "lua/lua.h"
    #include "lua/lualib.h"
    #include "lua/lauxlib.h"
}

/*  Lua Sandbox object
*   This object will contain the variables and functions 
*   which interact with a lua_State
*/
class luaSandbox
{
    private:
    lua_State * state;
    //  Binds API functions to the lua state
    void bindAPI();

    public:
    //  Defined maximum byte size of the Lua memory block
    long int memCapacity;
    //  Current byte size of the Lua memory block
    long int memSize;

    //  Read a global variable from the Lua environment
    void getGlobal(const char* name, int value);
    void getGlobal(const char* name, double value);
    void getGlobal(const char* name, char* value);

}luaSandbox;




