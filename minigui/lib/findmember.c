#include "../include/myarg.h"

DLGTEMPLATE DlgFindMember =
{
    WS_BORDER | WS_CAPTION |  WS_CHILD, 
    WS_EX_NONE,
    0, 0, 700, 400, 
    FINDCOMMUNITY,
    0, 0,
    FINDMEMBER_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlFindMember [] =
{ 
	{
        CTRL_MLEDIT,
        WS_VISIBLE | WS_BORDER | WS_VSCROLL | WS_HSCROLL | ES_READONLY
            |/* ES_BASELINE | ES_AUTOWRAP |*/ ES_NOHIDESEL | ES_NOHIDESEL,//| WS_DISABLED,
        0, 0, 680, 370, 
        IDC_FM_CHARS, 
        NULL,
        0,
        //WS_EX_TRANSPARENT 
	}
};
static char *strcatmember()
{
	char *tmp=(char *)malloc(sizeof(char)*LONG_BUFF);
	printf("Id:%d\nName:%s\nSno:%s\nSex:%s\nPhone:%s\nState:%d\n",member_i[0].id,member_i[0].name,member_i[0].sno,member_i[0].sex,member_i[0].phone,member_i[0].state);fflush(stdout);
	sprintf(tmp,"Id:%d\nName:%s\nSno:%s\nSex:%s\nPhone:%s\nState:%d\n",member_i[0].id,member_i[0].name,member_i[0].sno,member_i[0].sex,member_i[0].phone,member_i[0].state);
	return tmp;
}    
int FindMemberBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    HWND hwnd;

    switch (message) {
    case MSG_INITDIALOG:{
		SetWindowText(GetDlgItem(hDlg, IDC_FM_CHARS),strcatmember());
		return 1;
	}
		case MSG_CLOSE:
			EndDialog (hDlg, IDCANCEL);
        break;
    }    
    return DefaultDialogProc (hDlg, message, wParam, lParam);
}
