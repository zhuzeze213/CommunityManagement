#include "../include/member.h"
#include "../minigui/include/myarg.h"
static int MainWinProc(HWND hWnd,int message,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	struct tm *nowtm;
    time_t nowtime_t,inittime_t;
	char timebuff[SHORT_BUFF],welcome[MID_BUFF],communitybuff[LONG_BUFF],activitybuff[MID_BUFF],applybuff[MID_BUFF],apply_activitybuff[MID_BUFF],infobuff[MID_BUFF];
	int line_count=0;
	memset(timebuff,0,SHORT_BUFF);
	memset(welcome,0,MID_BUFF);
	memset(communitybuff,0,LONG_BUFF);
	memset(activitybuff,0,MID_BUFF);
	memset(applybuff,0,MID_BUFF);
	memset(apply_activitybuff,0,MID_BUFF);
	memset(infobuff,0,MID_BUFF);
	switch(message){
		case MSG_CREATE:
			inittime_t=time(NULL);
			SetTimer(hWnd,ID_TIMER,TIME_FLUSH);
			//SetWindowFont(hWnd, CreateLogFontByName("rbf-fmfsong-rrncnn-12-12-GB2312-0"));
			return 0;
		case MSG_TIMER:
			check();
			InvalidateRect (hWnd, NULL, TRUE);
			return 0;
		case MSG_PAINT:
			nowtime_t=time(NULL);
			nowtm=localtime(&nowtime_t);
			sprintf(welcome,"Welcome back:%s",user_name);			
			sprintf(timebuff,"Now,time is %02d:%02d:%02d",nowtm->tm_hour,nowtm->tm_min,nowtm->tm_sec);
			sprintf(communitybuff,"You have already attended %d communities: ",check_community_num);
			int i;
			for(i=0;i<check_community_num;i++){
				char tmp[MID_BUFF];
				sprintf(tmp,"ID:%d grant:%d buddy:%d~",check_community_id[i],check_grant[i],check_per_num[i]);	
				strcat(communitybuff,tmp);
			}
			sprintf(activitybuff,"You have %d activities",check_activity_num);
			sprintf(applybuff,"You have %d member applies no handle",check_apply_num);
			sprintf(apply_activitybuff,"You have %d activities applies no handle",check_apply_activity_num);
			sprintf(infobuff,"You have %d information",check_info_num);
			hdc=BeginPaint(hWnd);
			TextOut(hdc,0,(line_count++)*WORD_HEIGHT,welcome);
			TextOut(hdc,0,(line_count++)*WORD_HEIGHT,timebuff);
			TextOut(hdc,0,(line_count++)*WORD_HEIGHT,communitybuff);
			TextOut(hdc,0,(line_count++)*WORD_HEIGHT,activitybuff);
			TextOut(hdc,0,(line_count++)*WORD_HEIGHT,applybuff);
			TextOut(hdc,0,(line_count++)*WORD_HEIGHT,apply_activitybuff);
			TextOut(hdc,0,(line_count++)*WORD_HEIGHT,infobuff);
			EndPaint(hWnd,hdc);
			return 0;
		case MSG_COMMAND:
			switch (wParam) {
				case IDM_REGISTER:
				DlgAddmember.controls=CtrlAddmember;
				DialogBoxIndirectParam (&DlgAddmember, HWND_DESKTOP, AddmemberBoxProc, 0L);
				break;
				
				case IDM_LOOK_INFOMATION:
				DlgLookInformation.controls=CtrlLookInformation;
				DialogBoxIndirectParam (&DlgLookInformation, HWND_DESKTOP, LookInformationBoxProc, 0L);
				break;
				
				case IDM_ADD_COMMUNITY:
				DlgAddCommunity.controls = CtrlAddCommunity;
				DialogBoxIndirectParam (&DlgAddCommunity, HWND_DESKTOP, AddCommunityBoxProc, 0L);
				break;
				
				case IDM_LOOK_COMMUNITY:
				DlgLookCommunity.controls = CtrlLookCommunity;
				DlgLookCommunity.controlnr = LOOKCOMMUNITY_ELEMENT_NUM;
				DialogBoxIndirectParam (&DlgLookCommunity, HWND_DESKTOP, LookCommunityBoxProc, 0L);
				break;
				
				case IDM_APPLY:
				DlgApplyCommunity.controls = CtrlApplyCommunity;
				DialogBoxIndirectParam (&DlgApplyCommunity, HWND_DESKTOP, ApplyCommunityBoxProc, 0L);
				break;

				case IDM_ADD_MEMBER:
				DlgLookApply.controls = CtrlLookApply;
				DialogBoxIndirectParam (&DlgLookApply, HWND_DESKTOP, LookApplyBoxProc, 0L);
				break;
				
				case IDM_LOOK_MEMBER:
				DlgLookMember.controls = CtrlLookMember;
				DialogBoxIndirectParam (&DlgLookMember, HWND_DESKTOP, LookMemberBoxProc, 0L);
				break;
		
				case IDM_DELETE_MEMBER:
				DlgDeleteMember.controls = CtrlDeleteMember;
				DialogBoxIndirectParam (&DlgDeleteMember, HWND_DESKTOP, DeleteMemberBoxProc, 0L);
				break;
				
				case IDM_SEND_MESSAGE:
				DlgSendMessage.controls = CtrlSendMessage;
				DialogBoxIndirectParam (&DlgSendMessage, HWND_DESKTOP, SendMessageBoxProc, 0L);
				break;
				
				case IDM_RECEIVE_MESSAGE:
				DlgReceiveMessage.controls = CtrlReceiveMessage;
				DialogBoxIndirectParam (&DlgReceiveMessage, HWND_DESKTOP, ReceiveMessageBoxProc, 0L);
				break;
			}
			return 0;
		
		case MSG_CLOSE:
		DestroyMainWindow(hWnd);
		PostQuitMessage(hWnd);
		__setstate(user_name,NOONLINE);
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
