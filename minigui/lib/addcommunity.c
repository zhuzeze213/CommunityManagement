#include "../include/myarg.h"

DLGTEMPLATE DlgAddCommunity =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    100, 100, 330, 400,
    ADDCOMMUNITY,
    0, 0,
    ADDCOMMUNITY_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlAddCommunity[] =
{
	/* name */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 25, 70, 30,
        IDC_STATIC,
        ADC_NAME,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 20, 190, 30,
        IDC_ADC_NAME,
        NULL,
        0
    },
	/* data */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 80, 70, 30,
        IDC_STATIC,
        ADC_DATA,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 75, 190, 30,
        IDC_ADC_DATA,
        NULL,
        0
    },
	/* phone */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 135, 70, 30,
        IDC_STATIC,
        ADC_PHONE,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 130, 190, 30,
        IDC_ADC_PHONE,
        NULL,
        0
    },
	/* master id */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 195, 70, 30,
        IDC_STATIC,
        ADC_MID,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 190, 190, 30,
        IDC_ADC_MID,
        NULL,
        0
    },
	/* information */
	{
        CTRL_STATIC,
        WS_VISIBLE | SS_SIMPLE, 
        20, 250, 70, 30,
        IDC_STATIC,
        ADC_INFO,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        80, 245, 190, 30,
        IDC_ADC_INFO,
        NULL,
        0
    },
	/* 2 buttons */
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        70, 300, 80, 30,
        IDB_ADC_SUBMIT,
        ADC_SUBMIT,
        0
    },
	{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        170, 300, 80, 30,
        IDB_ADC_CANCEL,
        ADC_CANCEL,
        0
    },	
};
static void addcommunity(HWND hDlg)
{
	GetWindowText (GetDlgItem (hDlg, IDC_ADC_NAME), community_z[0].c_name, NAME_LENGTH);
	GetWindowText (GetDlgItem (hDlg, IDC_ADC_DATA), community_z[0].c_data, DATA_LENGTH);
	GetWindowText (GetDlgItem (hDlg, IDC_ADC_PHONE), community_z[0].c_phone, PHONE_LENGTH);
	char tmp[SHORT_BUFF];
	GetWindowText (GetDlgItem (hDlg, IDC_ADC_MID), tmp, SHORT_BUFF);
	community_z[0].master_no=atoi(tmp);
	GetWindowText (GetDlgItem (hDlg, IDC_ADC_INFO), community_z[0].c_information,TEXT_LENGTH);
	
	if(__addcommunity(&(community_z[0]))==SUCCESS){
		MessageBox (hDlg,  "Operation Success", "Attention",MB_OK);
	}
	else
		MessageBox (hDlg, "Operation Fail", "Attention", MB_OK);
}
int AddCommunityBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    switch (message) { 
		case MSG_COMMAND:{
			switch (wParam) {
				case IDB_ADC_SUBMIT:			
					addcommunity(hDlg);
					EndDialog (hDlg, wParam);
					break;
				case IDB_ADC_CANCEL:
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
