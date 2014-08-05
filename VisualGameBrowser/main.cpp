/* Visual Game Browser */

#include <Windows.h>
#include <vector>
#include <iostream>

#include "Game.h"

using namespace std;

string get_current_path();
vector<string> get_all_companies(string);
vector<string> get_all_directory_names(string);
vector<string> get_all_file_names(string);

int main(int argc, char **argv)
{
	int stop;
	string sPath = get_current_path();
	char rom_path[200];
	sprintf(rom_path, "%s\\ROMs", sPath.c_str());
	vector<string> companies = get_all_companies(rom_path);
	vector<string> names = get_all_file_names(sPath);
	cout << names[0].c_str();
	cin >> stop;
}

string get_current_path() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

vector<string> get_all_companies(string path)
{
	vector<string> companies = get_all_directory_names(path);
	return companies;
}

vector<string> get_all_directory_names(string folder)
{
	vector<string> names;
	char search_path[200];
	sprintf(search_path, "%s\\*", folder.c_str());
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path, &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				if (strcmp(fd.cFileName, ".") && strcmp(fd.cFileName, ".."))
				{
					names.push_back(fd.cFileName);
				}
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}

vector<string> get_all_file_names(string folder)
{
	vector<string> names;
	char search_path[200];
	sprintf(search_path, "%s\\*.*", folder.c_str());
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path, &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				names.push_back(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}