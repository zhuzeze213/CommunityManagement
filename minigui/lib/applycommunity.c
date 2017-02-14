#include "../include/myarg.h"

DLGTEMPLATE DlgApplyCommunity =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    100, 100, 330, 150,
    APPLYCOMMUNITY,
    0, 0,
    APPLYCOMMUNITY_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlApplyCommunity[] =
{
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 40, 100, 85,
        IDC_AC_INPUT_ID,
        AC_INPUT_ID,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        110, 35, 160, 30,
        IDC_AC_ID,
        NULL,
        0
    },
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        70, 80, 50, 30,
        IDB_AC_APPLY,
        AC_APPLY_CAPTION,
        0
    },
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        170, 80, 80, 30,
        IDB_AC_CANCEL,
        AC_CANCEL_CAPTION,
        0
    },
};
static void applycommunity(HWND hDlg)
{
	char tmp[SHORT_BUFF];
	GetWindowText (GetDlgItem (hDlg,IDC_AC_ID),tmp, SHORT_BUFF);
	if(__applycommunity(atoi(tmp))==SUCCESS)
		MessageBox (hDlg,  "Operation Success", "Attention",MB_OK);
	else
		MessageBox (hDlg, "Operation Fail", "Attention", MB_OK);
}
int ApplyCommunityBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    switch (message) { 

		case MSG_COMMAND:{
			switch (wParam) {
				case IDB_AC_APPLY:			
					applycommunity(hDlg);
					EndDialog (hDlg, wParam);
					break;
				case IDB_AC_CANCEL:
					EndDialog (hDlg, wParam);
					break;		
			}
			break;
        }
		case MSG_CLOSE:{
			EndDialog (hDlg, 0);
			break;
		}
    }
    return DefaultDialogProc (hDlg, message, wParam, lParam);
}


#ifdef _MGRM_THREADS
#include <minigui/dti.c>
#endif
