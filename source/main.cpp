#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h> 

extern "C"{
    #include <lua/lua.h>
    #include <lua/lualib.h>
    #include <lua/lauxlib.h>
}


int main(int argc, char* argv[])
{
    u32 keysDown;

	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

    printf("Press START + SELECT to close...");

	// Main loop
	while (aptMainLoop())
	{              
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();
        keysDown = hidKeysDown();

		// Your code goes here

		if (keysDown & (KEY_START | KEY_SELECT) )
			break; // break in order to return to hbmenu
		
	}

	gfxExit();
	return 0;
}
