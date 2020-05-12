#include "sandbox.h"

//  TODO: track memory block size
void* LuaSandbox::allocator(void *ud, void *ptr, size_t osize, size_t nsize)
{
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