/* Regwrite - function for writing to Windows registry */
#include "regwrite.h"

void regWriteStr(
     const char *szKeyPath, 
     const char *szKeyName, 
     const char *szKeyValue) {
  HKEY hSubkey;
  DWORD dwDisposition;

  //create new key
  LRESULT lReturnValue = RegCreateKeyEx(
      HKEY_CURRENT_USER, 
      szKeyPath,
      0,  //Reserved
      "String?", // Ignored if the key exists 
      REG_OPTION_NON_VOLATILE, 
      KEY_ALL_ACCESS, 
      NULL, // handle cannot be inherited
      &hSubkey, // pointer to result 
      &dwDisposition
  );

  if (lReturnValue == ERROR_SUCCESS) {
    printf("Created/opened new subkey.\n");
    if (dwDisposition == REG_OPENED_EXISTING_KEY) {
      printf("%s already exists, is now opened.\n", szKeyPath);
    }
    else {
      printf("%s created, is now opened.\n", szKeyPath);
    }
  } else {
    printf("Did not open new subkey :(\n");
  }

  // Set Value
  LPCTSTR value = TEXT(szKeyName);
  LPCTSTR data = szKeyValue;

  LONG setRes = RegSetValueEx (hSubkey, 
      value, 
      0, 
      REG_SZ, 
      (LPBYTE)data, 
      strlen(data)+1);

  if (setRes == ERROR_SUCCESS) {
    printf("Wrote:\n\tPath = %s\n\tKey  = %s\n\tVal  = %s\n",
        szKeyPath,
        szKeyName,
        szKeyValue
    );
  } else {
    printf("Error writing to Registry (%d).\n", setRes);
  }

  //clean up
  RegCloseKey(hSubkey);
}

