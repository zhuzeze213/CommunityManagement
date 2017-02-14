#include "../include/myarg.h"

static GHANDLE add_class_item (HWND hlist, PLVITEM lvItem, GHANDLE classent)
{
    LVSUBITEM subdata;
    GHANDLE item = SendMessage (hlist, LVM_ADDITEM, classent, (LPARAM)lvItem);

    subdata.nItem = lvItem->nItem;
    subdata.subItem = 0;
    subdata.pszText = rm_classes[lvItem->nItem];
    subdata.nTextColor = PIXEL_black;
    subdata.flags = 0;
    subdata.image = 0;
    SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);

    return item;
}

static GHANDLE add_score_item (HWND hlist, PLVITEM lvItem, GHANDLE classent)
{
    char buff[MID_BUFF];
    LVSUBITEM subdata;
    GHANDLE item = SendMessage (hlist, LVM_ADDITEM, classent, (LPARAM)lvItem);
    int i = lvItem->nItem;
    int j=0;

    subdata.flags = 0;
    subdata.image = 0;
    subdata.nItem = lvItem->nItem;

	subdata.subItem = j++;
	sprintf (buff, "%d", message_i[i].m_id);
	subdata.pszText = buff;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);

	subdata.subItem = j++;
	subdata.pszText = message_i[i].i_text;
	subdata.nTextMax=TEXT_LENGTH;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = message_i[i].i_data;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	
    return item;
}

int ReceiveMessageBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    HWND hListView;
    hListView = GetDlgItem (hDlg, IDC_LC_LISTVIEW);

    switch (message){    
		case MSG_INITDIALOG:{
			rm_classes=(char **)malloc(sizeof(char *)*check_community_num);
			int i, j;
			for(i=0;i<check_community_num;i++){
				rm_classes[i]=(char *)malloc(sizeof(char)*SHORT_BUFF);
				char tmp[SHORT_BUFF];
				sprintf(tmp,"%d",check_community_id[i]);
				strcpy(rm_classes[i],tmp);
			}
			LVITEM item;
			LVCOLUMN lvcol;
			GHANDLE hitem;
			__receivemessage();
			for (i = 0; i < RM_COL_NR; i++) {
				lvcol.nCols = i;
				lvcol.pszHeadText = rm_caption[i];
				if(i==1)
					lvcol.width = TEXT_LENGTH;
				else
					lvcol.width = 75;
				lvcol.pfnCompare = NULL;
				lvcol.colFlags = 0;
				SendMessage (hListView, LVM_ADDCOLUMN, 0, (LPARAM) &lvcol);
			}
			item.dwFlags &= ~LVIF_FOLD;
			item.nItemHeight = 25;
		
			SendMessage (hListView, MSG_FREEZECTRL, TRUE, 0);
			hitem = 0;
			for (i = 0; i < check_community_num; i++) {
				item.nItem = i;
				hitem = add_class_item (hListView, &item, 0);

				for (j = (i==0?0:message_in_num[i-1]); j < message_in_num[i]; j++) {
					item.nItem = j;
					add_score_item (hListView, &item, hitem);
				}

			}
			SendMessage (hListView, MSG_FREEZECTRL, FALSE, 0);
			break;
		}
		

		case MSG_CLOSE:{
			free(rm_classes);
			EndDialog (hDlg, 0);
			break;
		}
    }
    return DefaultDialogProc (hDlg, message, wParam, lParam);
}

CTRLDATA CtrlReceiveMessage[] =
{
	{
        "listview",
        /*WS_BORDER |*/ WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LVS_TREEVIEW,
         10, 10, 320, 220,
        IDC_RM_LISTVIEW,
        RECEIVEMESSAGE,
        0
    },

	{
		"button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        10, 300, 80, 30,
        IDB_RM_PRI,
        IDC_RM_PRI,
        0
	},
	{
		"button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        210, 300, 80, 30,
        IDB_RM_NEXT,
        IDC_RM_NEXT,
        0
	},
};

DLGTEMPLATE DlgReceiveMessage =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    0, 0, 400, 400,
    RECEIVEMESSAGE,
    0, 0,
    RECEIVEMESSAGE_ELEMENT_NUM, NULL,
    0
};

#ifdef _MGRM_THREADS
#include <minigui/dti.c>
#endif
