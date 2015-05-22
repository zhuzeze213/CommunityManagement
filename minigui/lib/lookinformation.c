#include "../include/myarg.h"

DLGTEMPLATE DlgLookInformation =
{
    WS_BORDER | WS_CAPTION |  WS_CHILD, 
    WS_EX_NONE,
    0, 0, 700, 400, 
    LOOKINFORMATION,
    0, 0,
    LOOKINFORMATION_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlLookInformation [] =
{ 
	{
        CTRL_MLEDIT,
        WS_VISIBLE | WS_BORDER | WS_VSCROLL | WS_HSCROLL | ES_READONLY
            |/* ES_BASELINE | ES_AUTOWRAP |*/ ES_NOHIDESEL | ES_NOHIDESEL,//| WS_DISABLED,
        0, 0, 680, 370, 
        IDC_LI_CHARS, 
        NULL,
        0,
        //WS_EX_TRANSPARENT 
	}
};
static char *strcatmember()
{
	char *tmp=(char *)malloc(sizeof(char)*LONG_BUFF);
	sprintf(tmp,"id:%d\nname:%s\nsno:%s\nsex:%s\nphone:%s\n",member_z.id,member_z.name,member_z.sno,member_z.sex,member_z.phone);
	return tmp;
}    
int LookInformationBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    HWND hwnd;

    switch (message) {
    case MSG_INITDIALOG:{
		SetWindowText(GetDlgItem(hDlg, IDC_LI_CHARS),strcatmember());
		return 1;
	}
		case MSG_CLOSE:
			EndDialog (hDlg, IDCANCEL);
        break;
    }    
    return DefaultDialogProc (hDlg, message, wParam, lParam);
}
