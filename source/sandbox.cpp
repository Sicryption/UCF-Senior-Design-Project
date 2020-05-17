#include "sandbox.h"
#include "userAPI.h"

/*
    Comparison oparations for the memBlock object.
    all comparisons are dependent on == and <
*/

std::pair<std::string, lua_CFunction> enabledFunctions[] = {
    std::make_pair( "println" , UserAPI::print)
};

inline bool operator ==  (LuaSandbox::memBlock a, LuaSandbox::memBlock b)
{
    return (a.head == b.head) && (a.size == b.size);
}
inline bool operator !=  (LuaSandbox::memBlock a, LuaSandbox::memBlock b)
{
    return !(a == b);
}
inline bool operator <   (LuaSandbox::memBlock a, LuaSandbox::memBlock b)
{
    return a.head < b.head;
}
inline bool operator >   (LuaSandbox::memBlock a, LuaSandbox::memBlock b)
{
    return b < a;
}
inline bool operator <=  (LuaSandbox::memBlock a, LuaSandbox::memBlock b)
{
    return !(a>b);
}
inline bool operator >=  (LuaSandbox::memBlock a, LuaSandbox::memBlock b)
{
    return !(a<b);
}

void* LuaSandbox::allocator(void *ud, void *ptr, size_t osize, size_t nsize)
{
    memBlock * mem = NULL;

    // Free
    if(nsize == 0)
    {
        // search for the memory block
        for (unsigned int i = 0; i < blockList.size(); i++)
        {
            // block is found
            if(blockList.at(i)->head == ptr)
            {
                // erase block
                blockList.erase(blockList.begin() + i);
                break;
            }
        }

        return NULL;
    }

    //  Allocate
    if( osize == 0)
    {//  No space allocated, create a new memory block
        mem = new memBlock(malloc(nsize),nsize);
    } else 
    {// Adjust an existing memory block
        // sum 
        size_t memTotal = getTotalMemoryUsed();

        if( memTotal < (nsize - osize) && 
            memTotal + (nsize - osize) < SANDBOX_MEM_CAPACITY)
        {
            mem = searchBlockList(ptr);
            if(mem == NULL){
                mem = new memBlock(ptr,nsize);
            }
            mem->head = realloc(ptr,nsize);
            mem->size = nsize;
        }
        
    }

    return mem;
}

LuaSandbox::memBlock* LuaSandbox::searchBlockList(void* ptr)
{
    if(ptr == NULL){return NULL;}

        for (unsigned int i = 0; i <blockList.size(); ++i)
        {
            LuaSandbox::memBlock* m = blockList.at(i);
            if(m->head == ptr)
            {
                return m;
            }
        }
    return NULL;
}

size_t LuaSandbox::getTotalMemoryUsed()
{
    size_t size = 0;
    for (unsigned int i = 0; i <blockList.size(); ++i)
    {
        size += blockList.at(i)->size;
    }
    return size;
}


void LuaSandbox::execute(std::string text)
{
//  TODO: Needs a more thorough test
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

void LuaSandbox::bindAPI()
{
    
    for(std::pair<std::string, lua_CFunction> func : enabledFunctions)
    {
        lua_pushcfunction(state, func.second);
        lua_setglobal(state, func.first.c_str());
    }
    
}