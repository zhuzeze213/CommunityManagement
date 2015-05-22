#include "../include/myarg.h"

int have_verify=0;
DLGTEMPLATE DlgLogin =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    100, 100, 330, 220,
    LOGIN,
    0, 0,
    LOGIN_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlLogin[] =
{
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 25, 70, 30,
        IDC_STATIC,
        L_USERNAME,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 20, 190, 30,
        IDC_L_USERNAME,
        NULL,
        0
    },
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 80, 70, 85,
        IDC_STATIC,
        L_PASSWORD,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_PASSWORD,
        80, 75, 190, 30,
        IDC_L_PASSWORD,
        NULL,
        0
    },
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        70, 130, 50, 30,
        IDB_L_LOGIN,
        LOGIN,
        0
    },
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        170, 130, 80, 30,
        IDB_L_PASSERS_BY,
        L_PASSERS_BY,
        0
    },
};


static void verifyaccount(HWND hDlg)
{
	char password[PASSWORD_L_LENGTH];
	GetWindowText (GetDlgItem (hDlg, IDC_L_USERNAME), user_name, USERNAME_L_LENGTH);
	GetWindowText (GetDlgItem (hDlg, IDC_L_PASSWORD), password, PASSWORD_L_LENGTH);
	//printf("%s\n%s\n",username,password);
	if(!strcmp(user_name,TEST_NAME)&&!strcmp(password,TEST_PASSWORD)){
		user_grant=GRANT_ROOT;
		have_verify=1;	
	}
	else{
		if(__verifyaccount(user_name,password)==SUCCESS){
			have_verify=1;
			MessageBox (hDlg,  "Operation Success", "Attention",MB_OK);
			__getinformation(user_name);
			__setstate(user_name,ONLINE);
		}
		else
			MessageBox (hDlg, "Operation Fail", "Attention", MB_OK);
	}
	//printf("%d\n",user_grant);
}

int LoginBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    switch (message) { 

		case MSG_COMMAND:{
			switch (wParam) {
				case IDB_L_LOGIN:			
					verifyaccount(hDlg);
					if(have_verify)
						EndDialog (hDlg, wParam);
					break;
				case IDB_L_PASSERS_BY:
					user_grant=GRANT_PASSERS_BY;
					EndDialog (hDlg, wParam);
					break;		
			}
			break;
        }      
    }
    return DefaultDialogProc (hDlg, message, wParam, lParam);
}


#ifdef _MGRM_THREADS
#include <minigui/dti.c>
#endif
