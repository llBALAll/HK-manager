#include <Windows.h>
#include <time.h>
#include <iostream>

using namespace std;

HWND waitWinTitle (char* pTitle);
void editwindow (HWND myHandle);

int main () {

	FreeConsole(); // kill console window but process still alive

	HWND hwnd;

	while (TRUE) {

		// (CTRL + ALT + B) toogle borderless in active window
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x42) < 0)) {
			//printf("Key pressed: (CTRL + ALT + B)\n");
			// get handle of the top window
			hwnd = GetForegroundWindow();
			// toogle borderless
			editwindow (hwnd);
			// wait to dont spam commands
			Sleep(200);
		}

		// (CTRL + ALT + T) open one terminal
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x54) < 0)) {
			//printf("Key pressed: (CTRL + ALT + T)\n");
			// open a program
			ShellExecuteA (NULL, "open", "cmd.exe", "", NULL, SW_SHOW);
			// wait up to 2s the program starts and get handle finding by window title
			hwnd = waitWinTitle ("C:\\Windows\\System32\\cmd.exe");
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 450, 690, 884, 351, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);
			// wait to dont spam commands
			Sleep(200);
		}

		// (CTRL + ALT + S) open sublime 
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x53) < 0)) {
			//printf("Key pressed: (CTRL + ALT + S)\n");
			// open a program
			ShellExecuteA (NULL, "open", "C:\\Vinicius\\bin\\Sublime Text Build 3211 x64\\sublime_text.exe", "", NULL, SW_SHOW);
			// wait up to 2s the program starts and get handle finding by window title
			hwnd = waitWinTitle ("untitled - Sublime Text (UNREGISTERED)");
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 450, 90, 884, 895, SWP_SHOWWINDOW);
			// toogle borderless
			editwindow (hwnd);
			// wait to dont spam commands
			Sleep(200); 
		}

		// (CTRL + ALT + E) open emacs
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x45) < 0)) {
			//printf("Key pressed: (CTRL + ALT + E)\n");
			// open a program
			ShellExecuteA (NULL, "open", "C:\\Vinicius\\bin\\emacs-23.4\\bin\\runemacs.exe", "", NULL, SW_SHOW);
			// wait program start and get the handle of top active window
			Sleep(500);
			hwnd = GetForegroundWindow();
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 265, 45, 1632, 985, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);
			// wait to dont spam commands
			Sleep(200);
		}

		// (CTRL + ALT + Y) open two terminals side by side
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x59) < 0)) {
			//printf("Key pressed: (CTRL + ALT + Y)\n");
			// open a program
			ShellExecuteA (NULL, "open", "cmd.exe", "", NULL, SW_SHOW);
			// wait the program starts and get handle finding by window title, if windows title not found in 2 seconds, stop finding
			hwnd = waitWinTitle ("C:\\Windows\\System32\\cmd.exe");
			// set the window title bar
			SetWindowTextA (hwnd, "terminal 1");
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 101, 140, 887, 896, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);

			// open a program
			ShellExecuteA (NULL, "open", "cmd.exe", "", NULL, SW_SHOW);
			// wait up to 2s the program starts and get handle finding by window title
			hwnd = waitWinTitle ("C:\\Windows\\System32\\cmd.exe");
			// set the window title bar
			SetWindowTextA (hwnd, "terminal 2");
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 1000, 140, 887, 896, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);
			// wait to dont spam commands
			Sleep(200);
		}

		// (CTRL + ALT + W) open sublime and one terminal side by side
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x57) < 0)) {
			//printf("Key pressed: (CTRL + ALT + W)\n");
			// open a program
			ShellExecuteA (NULL, "open", "C:\\Vinicius\\bin\\Sublime Text Build 3211 x64\\sublime_text.exe", "", NULL, SW_SHOW);
			// wait up to 2s the program starts and get handle finding by window title
			hwnd = waitWinTitle ("untitled - Sublime Text (UNREGISTERED)");
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 101, 140, 887, 896, SWP_SHOWWINDOW);
			// toogle borderless
			editwindow (hwnd);

			// open a program
			ShellExecuteA (NULL, "open", "cmd.exe", "", NULL, SW_SHOW);
			// wait up to 2s the program starts and get handle finding by window title
			hwnd = waitWinTitle ("C:\\Windows\\System32\\cmd.exe");
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 1000, 140, 887, 896, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);
			// wait to dont spam commands
			Sleep(200);
		}


		Sleep(50); // wait to dont spam processing
	}
}

// wait up to 2s the program starts and get handle finding by window title, if windows title not found in 2 seconds, stop finding
HWND waitWinTitle (char* pTitle) {
	
	HWND handleWin;
	clock_t tik = 0;
	clock_t tok = 0;
	unsigned long long flagtimer = 0;

	tik = clock();
	while (1) {
		if ((handleWin = FindWindowA (NULL, pTitle)) != NULL) return handleWin;
		// wait 2 seconds finding the window title, if not found stop finding
		tok = clock();
		flagtimer = ((double)(tok-tik)) / CLOCKS_PER_SEC;
		if (flagtimer > 2) {
			//flagtimer = 0;
			return NULL;
		}
	}
}

// toogle borderless
void editwindow (HWND myHandle) {

	int winX,winY,winW,winH;

	LONG styles = GetWindowLong(myHandle, GWL_STYLE);
    if (styles == FALSE) {
        std::cout << "can not get style of the window!\n";
    }

	styles ^= WS_OVERLAPPEDWINDOW;

    RECT rct;

    if (GetWindowRect(myHandle, &rct) == FALSE) {
        std::cout << "can not get window rect dimmensions!\n";
    }

    winX = rct.left;
    winY = rct.top;
    winW = rct.right - rct.left;
    winH = rct.bottom - rct.top;

    if (SetWindowLong(myHandle, GWL_STYLE, styles) == FALSE) {
        std::cout << "can not set the window borderless!\n";
    }

    SetWindowPos(myHandle, NULL, winX, winY, winW, winH, SWP_FRAMECHANGED);
}