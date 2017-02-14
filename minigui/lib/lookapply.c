#include "../include/myarg.h"

int id[PER_MEMBER_NUM];
int id_index=0;
DLGTEMPLATE DlgLookApply =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    0, 0, 400, 400,
    LOOKAPPLY,
    0, 0,
    LOOKAPPLY_ELEMENT_NUM, NULL,
    0
};

CTRLDATA CtrlLookApply[] =
{
	{
        "listview",
        /*WS_BORDER |*/ WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LVS_TREEVIEW,
         10, 10, 320, 220,
        IDC_LA_LISTVIEW,
        LOOKAPPLY,
        0
    },
	{
        "button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
         10, 260, 80, 30,
        IDB_LA_AGGRE,
        LA_AGGRE,
        0
    },
    {
        "button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
         210, 255, 80, 30,
        IDB_LA_REFUSE,
        LA_REFUSE,
        0
    },
	{
        CTRL_EDIT,
        WS_VISIBLE | WS_TABSTOP | WS_BORDER ,
        320, 260, 60, 30,
        IDC_LA_APPLYID,
        NULL,
        0
    	},
	{
		"button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        10, 300, 80, 30,
        IDB_LA_PRI,
        IDC_LA_PRI,
        0
	},
	{
		"button",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        210, 300, 80, 30,
        IDB_LA_NEXT,
        IDC_LA_NEXT,
        0
	},
};

static GHANDLE add_class_item (HWND hlist, PLVITEM lvItem, GHANDLE classent)
{
    LVSUBITEM subdata;
    GHANDLE item = SendMessage (hlist, LVM_ADDITEM, classent, (LPARAM)lvItem);

    subdata.nItem = lvItem->nItem;
    subdata.subItem = 0;
    subdata.pszText = la_classes[lvItem->nItem];
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
	sprintf (buff, "%d", member_a[i].id);
	id[id_index++]=member_a[i].id;
	subdata.pszText = buff;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);

	subdata.subItem = j++;
	subdata.pszText = member_a[i].name;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = member_a[i].sno;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = member_a[i].sex;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	subdata.pszText = member_a[i].phone;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
	subdata.subItem = j++;
	sprintf (buff, "%d", member_a[i].state);
	subdata.pszText = buff;
	subdata.nTextColor = PIXEL_black;
	SendMessage (hlist, LVM_SETSUBITEM, item, (LPARAM) & subdata);
	
    return item;
}

int LookApplyBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
    HWND hListView;
    hListView = GetDlgItem (hDlg, IDC_LA_LISTVIEW);

    switch (message){    
		case MSG_INITDIALOG:{
        int i, j;
        LVITEM item;
        LVCOLUMN lvcol;
        GHANDLE hitem;
		__lookapply();
        for (i = 0; i < LA_COL_NR; i++) {
            lvcol.nCols = i;
            lvcol.pszHeadText = la_caption[i];
            lvcol.width = 75;
            lvcol.pfnCompare = NULL;
            lvcol.colFlags = 0;
            SendMessage (hListView, LVM_ADDCOLUMN, 0, (LPARAM) &lvcol);
        }
        item.dwFlags &= ~LVIF_FOLD;
        item.nItemHeight = 25;
		
        SendMessage (hListView, MSG_FREEZECTRL, TRUE, 0);
        hitem = 0;
        for (i = 0; i < LA_SUB_NUM; i++) {
            item.nItem = i;
            hitem = add_class_item (hListView, &item, 0);

            for (j = 0; j < apply_num; j++) {
                item.nItem = j;
                add_score_item (hListView, &item, hitem);
            }

        }
        SendMessage (hListView, MSG_FREEZECTRL, FALSE, 0);
        break;
		}
		
		case MSG_COMMAND:{
        int id = LOWORD (wParam);
        if (id == IDB_LA_AGGRE) {
		char apply_id[SHORT_BUFF];
		GetWindowText (GetDlgItem (hDlg, IDC_LA_APPLYID), apply_id, SHORT_BUFF);
		int i,c_id;
		for(i=0;i<check_community_num;i++){
			if(check_grant[i]==GRANT_CM){
				c_id=check_community_id[i];
				break;
			}
		}
		if(__agreeapply(atoi(apply_id),c_id)==SUCCESS){
			MessageBox (hDlg,  "Operation Success", "Attention",MB_OK);
		}
		else	
			MessageBox (hDlg,  "Operation Fail", "Attention",MB_OK);
		HLVITEM hItemSelected;
		//LVITEM lvItem;
		hItemSelected = SendMessage (hListView,LVM_GETSELECTEDITEM, 0, 0) ;
		SendMessage (hListView, LVM_DELITEM, 0, hItemSelected) ;	
	}
		
	else if(id==IDB_LA_REFUSE){
		char apply_id[SHORT_BUFF];
		GetWindowText (GetDlgItem (hDlg, IDC_LA_APPLYID), apply_id, SHORT_BUFF);
		int i,c_id;
		for(i=0;i<check_community_num;i++){
		if(check_grant[i]==GRANT_CM){
			c_id=check_community_id[i];
			break;
			}
		}
		if(__refuseapply(atoi(apply_id),c_id)==SUCCESS){
			MessageBox (hDlg,  "Operation Success", "Attention",MB_OK);
		}
		else	
			MessageBox (hDlg,  "Operation Fail", "Attention",MB_OK);
		HLVITEM hItemSelected;
		//LVITEM lvItem;
		hItemSelected = SendMessage (hListView,LVM_GETSELECTEDITEM, 0, 0) ;
		SendMessage (hListView, LVM_DELITEM, 0, hItemSelected) ;
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
