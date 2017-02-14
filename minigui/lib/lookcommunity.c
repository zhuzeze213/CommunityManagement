#include "../include/myarg.h"

static GHANDLE add_class_item (HWND hlist, PLVITEM lvItem, GHANDLE classent)
{
    LVSUBITEM subdata;
    GHANDLE item = SendMessage (hlist, LVM_ADDITEM, classent, (LPARAM)lvItem);

    subdata.nItem = lvItem->nItem;
    subdata.subItem = 0;
    subdata.pszText = lc_classes[lvItem->nItem];;
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
	sprintf (buff, "%d", community_z[i].c_id);
	subdata.pszText = buff;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);

	subdata.subItem = j++;
	subdata.pszText = community_z[i].c_name;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = community_z[i].c_data;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = community_z[i].c_phone;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	sprintf (buff, "%d", community_z[i].master_no);
	subdata.pszText = buff;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = community_z[i].c_information;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
    return item;
}

int LookCommunityBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    HWND hListView;
    hListView = GetDlgItem (hDlg, IDC_LC_LISTVIEW);

    switch (message){    
		case MSG_INITDIALOG:{
        int i, j;
        LVITEM item;
        LVCOLUMN lvcol;
        GHANDLE hitem;
	__lookcommunity();
        for (i = 0; i < LC_COL_NR; i++) {
            lvcol.nCols = i;
            lvcol.pszHeadText = lc_caption[i];
            lvcol.width = 75;
            lvcol.pfnCompare = NULL;
            lvcol.colFlags = 0;
            SendMessage (hListView, LVM_ADDCOLUMN, 0, (LPARAM) &lvcol);
        }
        item.dwFlags &= ~LVIF_FOLD;
        item.nItemHeight = 25;
		
        SendMessage (hListView, MSG_FREEZECTRL, TRUE, 0);
        hitem = 0;
        for (i = 0; i < LC_SUB_NUM; i++) {
            item.nItem = i;
            hitem = add_class_item (hListView, &item, 0);

            for (j = 0; j < community_num; j++) {
                item.nItem = j;
                add_score_item (hListView, &item, hitem);
            }

        }
        SendMessage (hListView, MSG_FREEZECTRL, FALSE, 0);
        break;
		}
		
		case MSG_COMMAND:{
        int id = LOWORD (wParam);
        if (id == IDB_FINDCOMMUNITY) {
		char tmp[SHORT_BUFF];
		GetWindowText (GetDlgItem (hDlg,IDC_COMMUNITY_ID),tmp, SHORT_BUFF);
		__findcommunity(atoi(tmp));
		DlgFindCommunity.controls=CtrlFindCommunity;
		DialogBoxIndirectParam (&DlgFindCommunity, hDlg, FindCommunityBoxProc, 0L);
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

CTRLDATA CtrlLookCommunity[] =
{
	{
        "listview",
        /*WS_BORDER |*/ WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LVS_TREEVIEW,
         10, 10, 320, 220,
        IDC_LC_LISTVIEW,
        LOOKCOMMUNITY,
        0
    },
	{
        "edit",
        WS_CHILD | WS_VISIBLE | WS_BORDER,
         10, 260, 80, 20,
        IDC_COMMUNITY_ID,
        "",
        0
    },
    {
        "button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
         210, 255, 80, 30,
        IDB_FINDCOMMUNITY,
        FINDCOMMUNITY,
        0
    },
	{
		"button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        10, 300, 80, 30,
        IDB_LC_PRI,
        IDC_LC_PRI,
        0
	},
	{
		"button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        210, 300, 80, 30,
        IDB_LC_NEXT,
        IDC_LC_NEXT,
        0
	},
};

DLGTEMPLATE DlgLookCommunity =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    0, 0, 400, 400,
    LOOKCOMMUNITY,
    0, 0,
    0, NULL,
    0
};

#ifdef _MGRM_THREADS
#include <minigui/dti.c>
#endif
