#include "../include/myarg.h"

DLGTEMPLATE DlgFindCommunity =
{
    WS_BORDER | WS_CAPTION |  WS_CHILD, 
    WS_EX_NONE,
    0, 0, 700, 400, 
    FINDCOMMUNITY,
    0, 0,
    FINDCOMMUNITY_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlFindCommunity [] =
{ 
	{
        CTRL_MLEDIT,
        WS_VISIBLE | WS_BORDER | WS_VSCROLL | WS_HSCROLL | ES_READONLY
            |/* ES_BASELINE | ES_AUTOWRAP |*/ ES_NOHIDESEL | ES_NOHIDESEL,//| WS_DISABLED,
        0, 0, 680, 370, 
        IDC_FC_CHARS, 
        NULL,
        0,
        //WS_EX_TRANSPARENT 
	}
};
static char *strcatcommunity()
{
	char *tmp=(char *)malloc(sizeof(char)*LONG_BUFF);
	sprintf(tmp,"Id:%d\nName:%s\nData:%s\nPhone:%s\nMid:%d\nInfo:%s\n",community_z[0].c_id,community_z[0].c_name,community_z[0].c_data,community_z[0].c_phone,community_z[0].master_no,community_z[0].c_information);
	return tmp;
}    
int FindCommunityBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    HWND hwnd;

    switch (message) {
    case MSG_INITDIALOG:{
		SetWindowText(GetDlgItem(hDlg, IDC_FC_CHARS),strcatcommunity());
		return 1;
	}
		case MSG_CLOSE:
			EndDialog (hDlg, IDCANCEL);
        break;
    }    
    return DefaultDialogProc (hDlg, message, wParam, lParam);
}
