#ifndef LOOKAPPLY_H
#define LOOKAPPLY_H

#define LOOKAPPLY "Apply Info"
#define LOOKAPPLY_ELEMENT_NUM 6

#define IDC_LA_LISTVIEW 60
#define IDB_LA_AGGRE 61
#define LA_AGGRE "Aggre"
#define IDB_LA_REFUSE 62
#define LA_REFUSE "Refuse"
#define IDC_LA_APPLYID 65
#define IDB_LA_PRI 63
#define IDC_LA_PRI "Pri"
#define IDB_LA_NEXT 64
#define IDC_LA_NEXT "Next"

#define LA_COL_NR 6
#define LA_SUB_NUM 1

static char *la_caption[LA_COL_NR]=
{
	"Id","Name","Sno","Sex","Phone","State"
};

static char *la_classes[LA_SUB_NUM]=
{
	"All"
};
#endif
