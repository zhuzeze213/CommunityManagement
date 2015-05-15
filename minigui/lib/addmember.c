#include "../include/myarg.h"

DLGTEMPLATE DlgAddmember =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    100, 100, 330, 400,
    ADDMEMBER,
    0, 0,
    ADDMEMBER_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlAddmember[] =
{
	/* name */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 25, 70, 30,
        IDC_STATIC,
        AM_NAME,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 20, 190, 30,
        IDC_AM_NAME,
        NULL,
        0
    },
	/* sno */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 80, 70, 30,
        IDC_STATIC,
        AM_SNO,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 75, 190, 30,
        IDC_AM_SNO,
        NULL,
        0
    },
	/* sex */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 135, 70, 30,
        IDC_STATIC,
        AM_SEX,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 130, 190, 30,
        IDC_AM_SEX,
        NULL,
        0
    },
	/* phone */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 195, 70, 30,
        IDC_STATIC,
        AM_PHONE,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 190, 190, 30,
        IDC_AM_PHONE,
        NULL,
        0
    },
	/* password */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 250, 70, 30,
        IDC_STATIC,
        AM_PASSWORD,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 245, 190, 30,
        IDC_AM_PASSWORD,
        NULL,
        0
    },
	/* 2 buttons */
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        70, 300, 80, 30,
        IDB_AM_SUBMIT,
        AM_SUBMIT,
        0
    },
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        170, 300, 80, 30,
        IDB_AM_CANCEL,
        AM_CANCEL,
        0
    },	
};
static void addmember(HWND hDlg)
{
	struct member addone;
	addone.state=INITSTATE;
	GetWindowText (GetDlgItem (hDlg, IDC_AM_NAME), addone.name, NAME_LENGTH);
	GetWindowText (GetDlgItem (hDlg, IDC_AM_SNO), addone.sno, SNO_LENGTH);
	GetWindowText (GetDlgItem (hDlg, IDC_AM_SEX), addone.sex, SEX_LENGTH);
	GetWindowText (GetDlgItem (hDlg, IDC_AM_PHONE), addone.phone, PHONE_LENGTH);
	GetWindowText (GetDlgItem (hDlg, IDC_AM_PASSWORD), addone.password, PASSWORD_LENGTH);
	
	if(__addmember(&addone)==SUCCESS)
		MessageBox (hDlg,  "Operation Success", "Attention",MB_OK);
	else
		MessageBox (hDlg, "Operation Fail", "Attention", MB_OK);
}
int AddmemberBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    switch (message) { 
		case MSG_COMMAND:{
			switch (wParam) {
				case IDB_AM_SUBMIT:			
					addmember(hDlg);
					EndDialog (hDlg, wParam);
					break;
				case IDB_AM_CANCEL:
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
