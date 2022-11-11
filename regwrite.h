#ifndef H_REGWRITE1
#define H_REGWRITE1

/*
 * Regwrite - a collection of functions for writing in Windows registry
 * regWriteStr writes a string value to HKEY_CURRENT_USER.
 *
 */

#include <windows.h>
#include <shlobj.h>
#include <cstdlib>
#include <cstdio>

void regWriteStr(const char *szKeyPath, const char *szKeyName, const char *szKeyValue);

#endif
