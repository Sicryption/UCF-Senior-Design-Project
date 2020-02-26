#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <3ds.h> 

extern "C"{
    #include <lua/lua.h>
    #include <lua/lualib.h>
    #include <lua/lauxlib.h>
}

#include "sandbox.h"

#define BUFFER_SIZE  256

char BUFFER[BUFFER_SIZE];
char BUFFER_COUNT;

int KEYBOARD_OPEN = 0;

int main(int argc, char* argv[])
{
    BUFFER_COUNT = 0;

	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

    lua_State *L = initializeSandbox();

    SwkbdState swkbd;
    SwkbdStatusData swkbStatus;
    SwkbdLearningData swkbLearning;
    SwkbdButton swkbButton = SWKBD_BUTTON_NONE;
    u64 swkbFeatures = SWKBD_ALLOW_HOME | SWKBD_ALLOW_POWER | SWKBD_ALLOW_RESET;
    u32 swkbValid = SWKBD_NOTEMPTY_NOTBLANK;

    u32 keyDown;
    
	// Main loop
	while (aptMainLoop())
	{
        KEYBOARD_OPEN = 0;
        
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		// Your code goes here
        keyDown = hidKeysDown();

        if( keyDown & KEY_R)
        {
            KEYBOARD_OPEN = 1;
            swkbdInit(&swkbd, SWKBD_TYPE_QWERTY , 1, BUFFER_SIZE - 1);
            swkbdSetFeatures(&swkbd, swkbFeatures );
            swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, swkbValid, 2);
            swkbButton = swkbdInputText(&swkbd,BUFFER, BUFFER_SIZE-1);
        }


        if( KEYBOARD_OPEN == 1)
        {   //  Read Keyboard input
            if(swkbButton != SWKBD_BUTTON_NONE)
            {
                //printf("You entered: %s\n", BUFFER);
                luaL_dostring(L,BUFFER);
            }else
            {
                printf("swkbd event: %d\n", swkbdGetResult(&swkbd));
            }
        }

		if (keyDown & (KEY_START | KEY_SELECT) )
			break; // break in order to return to hbmenu
		
	}

    lua_close(L);
	gfxExit();
	return 0;
}
