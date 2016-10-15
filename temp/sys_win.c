#include <windows.h>

#define MAX_NUM_ARGVS 50

int argc = 1;
char *largv[ MAX_NUM_ARGVS ];

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	*largv[0] = "";

	while ( *lpCmdLine && ( argc < MAX_NUM_ARGVS )) {
		while( *lpCmdLine && (( *lpCmdLine <= 32 ) || ( *lpCmdLine > 126 ))){
			lpCmdLine++;
		}

		if ( *lpCmdLine ) {
			largv[argc] = lpCmdLine;
			argc++;

			while ( *lpCmdLine && (( *lpCmdLine > 32) && ( *lpCmdLine <= 126))) {
				lpCmdLine++;
			}

			if ( *lpCmdLine ) {
				*lpCmdLine = 0;
				lpCmdLine++;
			}
		}
	}

	return 0; 
}