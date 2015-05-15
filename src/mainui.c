#include "../include/member.h"
#include "../minigui/include/myarg.h"
static int MainWinProc(HWND hWnd,int message,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	struct tm *nowtm;
    time_t nowtime_t,inittime_t;
	char buff[SHORT_BUFF],grant_information[MID_BUFF],welcome[MID_BUFF];
	memset(buff,0,SHORT_BUFF);memset(grant_information,0,MID_BUFF);memset(welcome,0,MID_BUFF);
	switch(message){
		case MSG_CREATE:
			inittime_t=time(NULL);
			SetTimer(hWnd,ID_TIMER,TIME_FLUSH);
			//SetWindowFont(hWnd, CreateLogFontByName("rbf-fmfsong-rrncnn-12-12-GB2312-0"));
			return 0;
		case MSG_TIMER:
			InvalidateRect (hWnd, NULL, TRUE);
			return 0;
		case MSG_PAINT:
			nowtime_t=time(NULL);
			nowtm=localtime(&nowtime_t);
			sprintf(grant_information,"your grant: %d",user_grant);
			sprintf(welcome,"Welcome back:%s",user_name);			
			sprintf(buff,"Now,time is %02d:%02d:%02d",nowtm->tm_hour,nowtm->tm_min,nowtm->tm_sec);
			//printf("%s\n%s\n%s\n",buff,grant_information,welcome);			
			hdc=BeginPaint(hWnd);
			TextOut(hdc,0,0,welcome);
			TextOut(hdc,0,WORD_HEIGHT,grant_information);
			TextOut(hdc,0,2*WORD_HEIGHT,buff);
			EndPaint(hWnd,hdc);
			return 0;
		case MSG_COMMAND:
			switch (wParam) {
				case IDM_ADD_MEMBER:
				DlgAddmember.controls=CtrlAddmember;
				DialogBoxIndirectParam (&DlgAddmember, HWND_DESKTOP, AddmemberBoxProc, 0L);
				break;
			}
			return 0;
		
		case MSG_CLOSE:
		DestroyMainWindow(hWnd);
		PostQuitMessage(hWnd);
		return 0;
	}
	return DefaultMainWinProc(hWnd,message,wParam,lParam);
}
static int MiniGUIMain(int argc,const char *argv[])
{
	MSG Msg;
	HWND hMainWnd;
	MAINWINCREATE CreateInfo;
	
	#ifdef _MGRM_PROCESSES
	JoinLayer(NAME_DEF_LAYER,PROJECT_NAME,0,0);
	if(!ServerStartup(0,0,0)){
		fprintf(stderr,"Can not start the server of Minigui_Processes:mginit.\n");
		return 1;
	}
	#endif
	/* login */
	DlgLogin.controls=CtrlLogin;
	DialogBoxIndirectParam (&DlgLogin, HWND_DESKTOP, LoginBoxProc, 0L);
	/*set the attribute that mainui have*/
	CreateInfo.dwStyle=WS_VISIBLE|WS_BORDER|WS_CAPTION|WS_MINIMIZEBOX|WS_HSCROLL|WS_VSCROLL;
	CreateInfo.dwExStyle=WS_EX_NONE;
	CreateInfo.spCaption=PROJECT_NAME;
	CreateInfo.hMenu=createmenu();
	CreateInfo.hCursor=GetSystemCursor(0);
	CreateInfo.hIcon=MAINHICON;
	CreateInfo.MainWindowProc=MainWinProc;
	CreateInfo.lx=MAINLX;
	CreateInfo.ty=MAINTY;
	CreateInfo.rx=MAINRX;
	CreateInfo.by=MAINBY;
	CreateInfo.iBkColor=COLOR_lightwhite;
	CreateInfo.dwAddData=DWADDDATA;
	CreateInfo.hHosting=HWND_DESKTOP;
	hMainWnd=CreateMainWindow(&CreateInfo);
	
	if(hMainWnd==HWND_INVALID)
		return FAIL;

	ShowWindow(hMainWnd,SW_SHOWNORMAL);
	while(GetMessage(&Msg,hMainWnd)){
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	MainWindowThreadCleanup(hMainWnd);
	return 0;
}

#ifndef _MGRM_PROCESSES
#include<minigui/dti.c>

#endif
