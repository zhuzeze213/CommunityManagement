#include "../include/myarg.h"

static HMENU member_menu(void)
{
	int count=0;
	HMENU hmnu;
	MENUITEMINFO mii;
	
	memset (&mii, 0, sizeof(MENUITEMINFO));
	mii.type = MFT_STRING;
	mii.id = IDM_MEMBER;
	mii.typedata =(DWORD)"Member";
	hmnu = CreatePopupMenu (&mii);
	
	memset (&mii, 0, sizeof(MENUITEMINFO));
	mii.type = MFT_STRING;
	mii.state = 0;
	mii.id = IDM_LOOK_MEMBER;
	mii.typedata = (DWORD)"Look";
	InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_DELETE_MEMBER;
    mii.typedata = (DWORD)"Delete";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_ADD_MEMBER;
    mii.typedata = (DWORD)"Add";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_FIND_MEMBER;
    mii.typedata = (DWORD)"Find";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
	mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_UPDATE_MEMBER;
    mii.typedata = (DWORD)"Update";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	return hmnu;

}

static HMENU community_menu(void)
{
	int count=0;
	HMENU hmnu;
	MENUITEMINFO mii;
	
	memset (&mii, 0, sizeof(MENUITEMINFO));
	mii.type = MFT_STRING;
	mii.id = IDM_COMMUNITY;
	mii.typedata =(DWORD)"Community";
	hmnu = CreatePopupMenu (&mii);
	
	
	mii.type = MFT_STRING;
	mii.state = 0;
	mii.id = IDM_LOOK_COMMUNITY;
	mii.typedata = (DWORD)"Look";
	InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_DELETE_COMMUNITY;
    mii.typedata = (DWORD)"Delete";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_ADD_COMMUNITY;
    mii.typedata = (DWORD)"Add";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_FIND_COMMUNITY;
    mii.typedata = (DWORD)"Find";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
	mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_UPDATE_COMMUNITY;
    mii.typedata = (DWORD)"Update";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	return hmnu;
}

static HMENU activity_menu(void)
{
	int count=0;
	HMENU hmnu;
	MENUITEMINFO mii;
	
	memset (&mii, 0, sizeof(MENUITEMINFO));
	mii.type = MFT_STRING;
	mii.id = IDM_AVTIVITY;
	mii.typedata =(DWORD)"Activity";
	hmnu = CreatePopupMenu (&mii);
	
	
	mii.type = MFT_STRING;
	mii.state = 0;
	mii.id = IDM_LOOK_AVTIVITY;
	mii.typedata = (DWORD)"Look";
	InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_DELETE_AVTIVITY;
    mii.typedata = (DWORD)"Delete";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_ADD_AVTIVITY;
    mii.typedata = (DWORD)"Add";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_FIND_AVTIVITY;
    mii.typedata = (DWORD)"Find";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
	mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_UPDATE_AVTIVITY;
    mii.typedata = (DWORD)"Update";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	return hmnu;
}

static HMENU information_menu(void)
{
	int count=0;
	HMENU hmnu;
	MENUITEMINFO mii;
	
	memset (&mii, 0, sizeof(MENUITEMINFO));
	mii.type = MFT_STRING;
	mii.id = IDM_INFORMATION;
	mii.typedata =(DWORD)"Information";
	hmnu = CreatePopupMenu (&mii);
	
	
	mii.type = MFT_STRING;
	mii.state = 0;
	mii.id = IDM_UPDATE_PASSWORD;
	mii.typedata = (DWORD)"Change Password";
	InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_LOOK_INFOMATION;
    mii.typedata = (DWORD)"Look";
    InsertMenuItem(hmnu, count++, TRUE, &mii);
	
    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_REGISTER;
    mii.typedata = (DWORD)"Register";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_APPLY;
    mii.typedata = (DWORD)"Apply";
    InsertMenuItem(hmnu, count++, TRUE, &mii);

    mii.type = MFT_STRING;
    mii.state = 0;
    mii.id = IDM_EXIT;
    mii.typedata = (DWORD)"Exit";
    InsertMenuItem(hmnu, count++, TRUE, &mii);
	return hmnu;
}

static HMENU about_menu(void)
{
	int count=0;
	HMENU hmnu;
	MENUITEMINFO mii;
	
	memset (&mii, 0, sizeof(MENUITEMINFO));
	mii.type = MFT_STRING;
	mii.id = IDM_ABOUT;
	mii.typedata =(DWORD)"About";
	hmnu = CreatePopupMenu (&mii);

	return hmnu;
}

HMENU createmenu(void)
{
	int count=0;
	HMENU hmnu;
	MENUITEMINFO mii;
	hmnu = CreateMenu();
	memset (&mii, 0, sizeof(MENUITEMINFO));
	mii.type = MFT_STRING;
	mii.id = IDM_1;
	mii.typedata =(DWORD)"Member";
	mii.hsubmenu =member_menu();
	InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.id = IDM_2;
    mii.typedata =(DWORD)"Community";
    mii.hsubmenu =community_menu();
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
    mii.type = MFT_STRING;
    mii.id = IDM_3;
    mii.typedata =(DWORD)"Activity";
    mii.hsubmenu =activity_menu();
    InsertMenuItem(hmnu, count++, TRUE, &mii);

	
	mii.type = MFT_STRING;
    mii.id = IDM_4;
    mii.typedata =(DWORD)"Information";
    mii.hsubmenu =information_menu();
    InsertMenuItem(hmnu, count++, TRUE, &mii);
	
	
	mii.type = MFT_STRING;
    mii.id = IDM_5;
    mii.typedata =(DWORD)"About";
    mii.hsubmenu =about_menu();
    InsertMenuItem(hmnu, count++, TRUE, &mii);
	return hmnu;
}


