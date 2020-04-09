#include <Windows.h>
#include <iostream>

using namespace std;

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

			Sleep(200); // wait to dont spam commands
		}

		// (CTRL + ALT + T) open one terminal
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x54) < 0)) {
			//printf("Key pressed: (CTRL + ALT + T)\n");

			// open a program
			ShellExecuteA (NULL, "open", "cmd.exe", "", NULL, SW_SHOW);
			// wait the program starts and get handle by window title
			while (1) {
				if ((hwnd = FindWindowA(NULL, "C:\\Windows\\System32\\cmd.exe")) != NULL) break;
			}
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 450, 690, 884, 351, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);

			Sleep(200); // wait to dont spam commands
		}

		// (CTRL + ALT + S) open sublime 
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x53) < 0)) {
			//printf("Key pressed: (CTRL + ALT + S)\n");

			// open a program
			ShellExecuteA (NULL, "open", "C:\\Vinicius\\bin\\Sublime Text Build 3211 x64\\sublime_text.exe", "", NULL, SW_SHOW);
			// wait the program starts and get handle by window title
			while (1) {
				if ((hwnd = FindWindowA(NULL, "untitled - Sublime Text (UNREGISTERED)")) != NULL) break;
			}
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 450, 90, 884, 895, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);

			Sleep(200); // wait to dont spam commands
		}

		// (CTRL + ALT + Y) open two terminals side by side
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x59) < 0)) {
			//printf("Key pressed: (CTRL + ALT + Y)\n");

			// open a program
			ShellExecuteA (NULL, "open", "cmd.exe", "", NULL, SW_SHOW);
			// wait the program starts and get handle by window title
			while (1) {
				if ((hwnd = FindWindowA(NULL, "C:\\Windows\\System32\\cmd.exe")) != NULL) break;
			}
			// set the window title barü
			SetWindowTextA (hwnd, "terminal 1");
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 101, 140, 887, 896, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);

			// open a program
			ShellExecuteA (NULL, "open", "cmd.exe", "", NULL, SW_SHOW);
			// wait the program starts and get handle by window title
			while (1) {
				if ((hwnd = FindWindowA(NULL, "C:\\Windows\\System32\\cmd.exe")) != NULL) break;
			}
			// set the window title bar
			SetWindowTextA (hwnd, "terminal 2");
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 1000, 140, 887, 896, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);

			Sleep(200); // wait to dont spam commands
		}

		// (CTRL + ALT + W) open sublime and one terminal side by side
		if ((GetAsyncKeyState(VK_CONTROL) < 0) && (GetAsyncKeyState(VK_MENU) < 0) && (GetAsyncKeyState(0x57) < 0)) {
			//printf("Key pressed: (CTRL + ALT + W)\n");

			// open a program
			ShellExecuteA (NULL, "open", "C:\\Vinicius\\bin\\Sublime Text Build 3211 x64\\sublime_text.exe", "", NULL, SW_SHOW);
			// wait the program starts and get handle by window title
			while (1) {
				if ((hwnd = FindWindowA(NULL, "untitled - Sublime Text (UNREGISTERED)")) != NULL) break;
			}
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 101, 140, 887, 896, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);

			// open a program
			ShellExecuteA (NULL, "open", "cmd.exe", "", NULL, SW_SHOW);
			// wait the program starts and get handle by window title
			while (1) {
				if ((hwnd = FindWindowA(NULL, "C:\\Windows\\System32\\cmd.exe")) != NULL) break;
			}
			// set size/position of window program
			SetWindowPos(hwnd, HWND_TOP, 1000, 140, 887, 896, SWP_SHOWWINDOW);
			// toogle borderless
			//editwindow (hwnd);
			
			Sleep(200); // wait to dont spam commands
		}


		Sleep(50); // // wait to dont spam processing
	}
}

// toogle borderless
void editwindow (HWND myHandle) {

	int winX,winY,winW,winH;

	LONG styles = GetWindowLong(myHandle, GWL_STYLE);
    if (styles == FALSE) {
        std::cout << "can get style of the window!\n";
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