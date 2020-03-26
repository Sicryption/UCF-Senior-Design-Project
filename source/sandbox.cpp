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
    //  Defined maximum byte size of the Lua memory block
    unsigned long int memCapacity;
    //  Current byte size of the Lua memory block
    unsigned long int memSize;

    lua_State * state;    

    //  Lua allocator function
    void * allocator(void *ud, void *ptr, size_t osize, size_t nsize);

    //  Binds API functions to the lua state
    void bindAPI();


    public:

    luaSandbox()
    {
        state = luaL_newstate();
    }

    unsigned long int getMemCapacity();
    unsigned long int getMemSize();

    unsigned long int setMemCapacity();
    unsigned long int setMemSize();
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
  
    //  Write a global variable from the Lua environment
    void setGlobal(const char* name, int value);
    void setGlobal(const char* name, double value);
    void setGlobal(const char* name, char* value);

    //  Execute Lua code
    void execute(const char* code);
    void execute(FILE * fp);

}luaSandbox;

//  TODO: track memory block size
void* allocator(void *ud, void *ptr, size_t osize, size_t nsize)
{
    (void)ud;  (void)osize;  /* not used */
    if (nsize == 0) {
        free(ptr);
        return NULL;
    }
    else
        return realloc(ptr, nsize);
}

