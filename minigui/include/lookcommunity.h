#ifndef LOOKCOMMUNITY_H
#define LOOKCOMMUNITY_H

#define LOOKCOMMUNITY "Community"
#define LOOKCOMMUNITY_ELEMENT_NUM 5

#define IDC_LC_LISTVIEW 60 

#define IDB_LC_PRI 61
#define IDC_LC_PRI "Pri"
#define IDB_LC_NEXT 62
#define IDC_LC_NEXT "Next"

#define IDC_COMMUNITY_ID 63

#define IDB_FINDCOMMUNITY 64
#define FINDCOMMUNITY "Find"

#define LC_SUB_NUM 1
#define LC_COL_NR 6

static char *lc_caption[LC_COL_NR]=
{
	"Id","Name","Data","Phone","Mid","info"
};

static char *lc_classes[LC_SUB_NUM]=
{
	"all"
};
#endif