#include "../include/myarg.h"

DLGTEMPLATE DlgSendMessage =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    100, 100, 330, 300,
    SENDMESSAGE,
    0, 0,
    SENDMESSAGE_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlSendMessage[] =
{
	/* name */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 25, 70, 30,
        IDC_STATIC,
        SM_ID,
        0
    },
	{
        CTRL_COMBOBOX,
        WS_VISIBLE | CBS_DROPDOWNLIST | CBS_NOTIFY,
        100, 20, 50, 30,
        IDC_SM_ID,
        "0",
        80
    },
	/* text */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 80, 70, 30,
        IDC_STATIC,
        SM_TEXT,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 75, 190, 30,
        IDC_SM_TEXT,
        NULL,
        0
    },
	/* data */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 135, 70, 30,
        IDC_STATIC,
        SM_DATA,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 130, 190, 30,
        IDC_SM_DATA,
        NULL,
        0
    },
	/* 2 buttons */
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        70, 200, 80, 30,
        IDB_SM_SUBMIT,
        SM_SEND,
        0
    },
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        170, 200, 80, 30,
        IDB_SM_CANCEL,
        SM_CANCEL,
        0
    },	
};

static void sendmessage(HWND hDlg)
{
	struct info_diffusion addone;
	addone.m_id=member_z.id;
	char tmp[SHORT_BUFF];
	GetWindowText (GetDlgItem (hDlg, IDC_SM_ID),tmp,SHORT_BUFF);
	addone.c_id=atoi(tmp);
	GetWindowText (GetDlgItem (hDlg, IDC_SM_TEXT), addone.i_text, TEXT_LENGTH);
	GetWindowText (GetDlgItem (hDlg, IDC_SM_DATA), addone.i_data, DATA_LENGTH);
	
	if(__sendmessage(&addone)==SUCCESS){
		MessageBox (hDlg,  "Operation Success", "Attention",MB_OK);
		//memcpy(&member_z,&addone,sizeof(struct member));
	}
	else
		MessageBox (hDlg, "Operation Fail", "Attention", MB_OK);
}
int SendMessageBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    switch (message) { 
	
		case MSG_INITDIALOG:{
			int i;
			for(i=0;i<check_community_num;i++) {
				char tmp[SHORT_BUFF];
				sprintf(tmp,"%d",check_community_id[i]);
				SendDlgItemMessage(hDlg, IDC_SM_ID, CB_ADDSTRING, 0, (LPARAM)tmp);
			}
			break;
		}
		
		case MSG_COMMAND:{
			switch (wParam) {
				case IDB_SM_SUBMIT:			
					sendmessage(hDlg);
					EndDialog (hDlg, wParam);
					break;
				case IDB_SM_CANCEL:
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
