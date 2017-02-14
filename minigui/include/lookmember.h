#ifndef LOOKMEMBER_H
#define LOOKMEMBER_H

#define LOOKMEMBER "Member"
#define LOOKMEMBER_ELEMENT_NUM 5

#define IDC_LM_LISTVIEW 60 

#define IDB_LM_PRI 61
#define IDC_LM_PRI "Pri"
#define IDB_LM_NEXT 62
#define IDC_LM_NEXT "Next"

#define IDC_LM_MEMBER_ID 63

#define IDB_LM_FINDMEMBER 64
#define FINDMEMBER "Find"

#define LM_SUB_NUM 1
#define LM_COL_NR 6

static char *lm_caption[LM_COL_NR]=
{
	"Id","Name","Sno","Sex","Phone","State"
};

/*static char *lm_classes[LM_SUB_NUM]=
{
	"all"
};*/
static char **lm_classes;
#endif
