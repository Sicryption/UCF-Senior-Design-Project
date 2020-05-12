#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include <map>
//#include <any>

#include "lua/lua.hpp"

#define SANDBOX_MEM_CAPACITY 1024

//typedef std::map<std::string, std::any > LuaTable;

/**  
 *  Lua Sandbox object
 * tracks memory size and capacity, handles Lua errors 
 * provides access functions to the Lua environment
 */
class LuaSandbox
{

private:
    ///  Maximum memory size in bytes
    unsigned long int memCapacity;

    ///  Current memory in use, in bytes
    unsigned long int memSize;

    ///  Head of the allocated memory block
    void* memHead;
    
    ///  Lua state object
    lua_State * state;    

    
    /**
     *  Custom Lua memory allocation function
     *  @param ud user defined data object
     *  @param ptr pointer to the start of the target memory block
     *  @param osize original size of the target memory block
     *  @param nsize desired size oth the target memory block
     *  @returns new pointer to the start of the target memory block, returns null if no space could be made
     */
    void * allocator(void *ud, void *ptr, size_t osize, size_t nsize);

    /**  Bind all User API functions to the Lua state */
    void bindAPI();


public:

    LuaSandbox()
    {
        state = luaL_newstate();
        memSize = 0;
        memCapacity = SANDBOX_MEM_CAPACITY;
        memHead = calloc(memCapacity, sizeof(void*) ) ;
        if(memHead == NULL)
        {
            std::cerr << "Error: memory allocation error, not enough space \n";
        }
    }

    ~LuaSandbox()
    {
        lua_close(state);
        free(memHead);
    }

    /**
     *  @returns memory capacity
     */
    unsigned long int getMemCapacity();

    /**
     *  @returns memory space in use
     */
    unsigned long int getMemSize();

    /**
     *  Set a new memory capacity
     */
    unsigned long int setMemCapacity();

    /**
     *  try to read the value of a double field with the given identifier
     *  @returns value assigned to the identifier in the lua environment
     *  @throw exception if variable either does not exist or, is of a different memory type
     */
    double tryGetDouble(std::string );

    /**
     *  try to read the value of a string field with the given identifier
     *  @returns value assigned to the identifier in the lua environment
     *  @throw exception if variable either does not exist or, is of a different memory type
     */
    std::string tryGetString(std::string );

    /**
     *  try to read the value of a boolean field with the given identifier
     *  @returns value assigned to the identifier in the lua environment
     *  @throw exception if variable either does not exist or, is of a different memory type
     */
    bool tryGetBool( std::string );

    /**
     *  try to return a table with the given identifier
     *  @returns value assigned to the identifier in the lua environment
     *  @throw exception if variable either does not exist or, is of a different memory type
     */
    //void tryGetTable( std::string );

    /**
     *  Declare or Assign a value in the environment
     *  @param identifier must be unique to avoid overwriting 
     *  @param data to be assigned
     *  @returns the value assigned
     */
    int setGlobal(std::string , int );
    double setGlobal(std::string , double );
    std::string setGlobal( std::string , std::string );

    /**
     *  Execute a chunk of lua code. 
     *  @throw exception if the system runs out of memory while copying the codeblock
     */
    void execute(std::string );
};



