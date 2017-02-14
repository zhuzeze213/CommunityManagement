#ifndef RECEIVEMESSAGE_H
#define RECEIVEMESSAGE_H

#define RECEIVEMESSAGE "Message"
#define RECEIVEMESSAGE_ELEMENT_NUM 3

#define IDC_RM_LISTVIEW 60 

#define IDB_RM_PRI 61
#define IDC_RM_PRI "Pri"
#define IDB_RM_NEXT 62
#define IDC_RM_NEXT "Next"

#define RM_COL_NR 3

static char *rm_caption[RM_COL_NR]=
{
	"M_id","Text","Date"
};

static char **rm_classes;

#endif