/* This head file include the name of functions in ../../src */
#ifndef UTIL_H
#define UTIL_H

#include "../../include/normal.h"

HMENU createmenu(void);

int LoginBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int AddmemberBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);

int LookInformationBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam);
#endif
