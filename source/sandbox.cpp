#include "sandbox.h"

void* LuaSandbox::allocator(void *ud, void *ptr, size_t osize, size_t nsize)
{
    //  TODO: track memory block size
    (void)ud;  (void)osize;  /* not used */
    if (nsize == 0) {
        free(ptr);
        return NULL;
    }
    else
        return realloc(ptr, nsize);
}

void LuaSandbox::execute(std::string text)
{
    // Temporary implementation, unprotected
    const char* temp = text.c_str();
    luaL_dostring(state,temp);
}

double LuaSandbox::tryGetDouble(std::string id)
{
    //  convert sting to const char*
    const char* n = id.c_str();

    //  push value unto the stack
    int ltype = lua_getglobal(state,n);

    //  convert value on the stack to a double 
    double value = lua_tonumber(state,-1);
    
    // value no longer needed, remove from the stack
    lua_remove(state,1);

    // throw an error if the type is wrong
    if(ltype != LUA_TNUMBER){
        throw ;
    }
    
    return value;
}

// TODO: test 
bool LuaSandbox::tryGetBool(std::string id)
{
    //  convert sting to const char*
    const char* n = id.c_str();

    //  push value unto the stack
    int ltype = lua_getglobal(state,n);

    //  convert value on the stack to a double 
    bool value = lua_toboolean(state,-1);
    
    // value no longer needed, remove from the stack
    lua_remove(state,1);

    // throw an error if the type is wrong
    if(ltype != LUA_TBOOLEAN){
        throw ;
    }
    
    return value;
}

// TODO: test 
std::string LuaSandbox::tryGetString(std::string id)
{
    //  convert sting to const char*
    const char* n = id.c_str();

    //  push value unto the stack
    int ltype = lua_getglobal(state,n);

    //  convert value on the stack to a double 
    std::string value = std::string( lua_tostring(state,-1));
    
    // value no longer needed, remove from the stack
    lua_remove(state,1);

    // throw an error if the type is wrong
    if(ltype != LUA_TBOOLEAN){
        throw ;
    }
    
    return value;
}