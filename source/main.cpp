#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h> 

/*
    The Lua API is built in C.
    In a C++ program it has to be included like this.
*/
extern "C"{
    #include <lua/lua.h>
    #include <lua/lualib.h>
    #include <lua/lauxlib.h>
}


int main(int argc, char* argv[])
{
    gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

    printf("Press START + SELECT to close...");

	// Main loop
	while (aptMainLoop())
	{              
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();
        u32 kd = hidKeysDown();

		// Your code goes here

		if (kd & (KEY_START | KEY_SELECT) )
			break; // break in order to return to hbmenu
		
	}

	gfxExit();
	return 0;
}
