#include "../include/myarg.h"

static GHANDLE add_class_item (HWND hlist, PLVITEM lvItem, GHANDLE classent)
{
    LVSUBITEM subdata;
    GHANDLE item = SendMessage (hlist, LVM_ADDITEM, classent, (LPARAM)lvItem);

    subdata.nItem = lvItem->nItem;
    subdata.subItem = 0;
    subdata.pszText = lm_classes[lvItem->nItem];
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
	sprintf (buff, "%d", member_i[i].id);
	subdata.pszText = buff;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);

	subdata.subItem = j++;
	subdata.pszText = member_i[i].name;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = member_i[i].sno;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = member_i[i].sex;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = member_i[i].phone;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	sprintf (buff, "%d", member_i[i].state);
	subdata.pszText = buff;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
    return item;
}

int LookMemberBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    HWND hListView;
    hListView = GetDlgItem (hDlg, IDC_LC_LISTVIEW);

    switch (message){    
		case MSG_INITDIALOG:{
	lm_classes=(char **)malloc(sizeof(char *)*check_community_num);
        int i, j;
	for(i=0;i<check_community_num;i++){
		lm_classes[i]=(char *)malloc(sizeof(char)*SHORT_BUFF);
		char tmp[SHORT_BUFF];
		sprintf(tmp,"%d",check_community_id[i]);
		strcpy(lm_classes[i],tmp);
	}
        LVITEM item;
        LVCOLUMN lvcol;
        GHANDLE hitem;
		__lookmember();
        for (i = 0; i < LM_COL_NR; i++) {
            lvcol.nCols = i;
            lvcol.pszHeadText = lm_caption[i];
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

            for (j = (i==0?0:in_num[i-1]); j < in_num[i]; j++) {
                item.nItem = j;
                add_score_item (hListView, &item, hitem);
            }

        }
        SendMessage (hListView, MSG_FREEZECTRL, FALSE, 0);
        break;
		}
		
		case MSG_COMMAND:{
        int id = LOWORD (wParam);
        if (id == IDB_LM_FINDMEMBER) {
		char tmp[SHORT_BUFF];
		GetWindowText (GetDlgItem (hDlg,IDC_LM_MEMBER_ID),tmp, SHORT_BUFF);
		__findmember(atoi(tmp));
		DlgFindMember.controls=CtrlFindMember;
		DialogBoxIndirectParam (&DlgFindMember, hDlg, FindMemberBoxProc, 0L);
	}
       	 break;
		}

		case MSG_CLOSE:{
	free(lm_classes);
        EndDialog (hDlg, 0);
        break;
		}
    }
    return DefaultDialogProc (hDlg, message, wParam, lParam);
}

CTRLDATA CtrlLookMember[] =
{
	{
        "listview",
        /*WS_BORDER |*/ WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LVS_TREEVIEW,
         10, 10, 320, 220,
        IDC_LM_LISTVIEW,
        LOOKMEMBER,
        0
    },
	{
        "edit",
        WS_CHILD | WS_VISIBLE | WS_BORDER,
         10, 260, 80, 20,
        IDC_LM_MEMBER_ID,
        "",
        0
    },
    {
        "button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
         210, 255, 80, 30,
        IDB_LM_FINDMEMBER,
        FINDMEMBER,
        0
    },
	{
		"button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        10, 300, 80, 30,
        IDB_LM_PRI,
        IDC_LM_PRI,
        0
	},
	{
		"button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        210, 300, 80, 30,
        IDB_LM_NEXT,
        IDC_LM_NEXT,
        0
	},
};

DLGTEMPLATE DlgLookMember =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    0, 0, 400, 400,
    LOOKMEMBER,
    0, 0,
    LOOKMEMBER_ELEMENT_NUM, NULL,
    0
};

#ifdef _MGRM_THREADS
#include <minigui/dti.c>
#endif
