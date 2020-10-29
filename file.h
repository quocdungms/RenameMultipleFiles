#pragma once
#include "dirent.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <winbase.h>
//#include <limits.h>
#include <windows.h>
#include <direct.h>
//#include <filesystem>

#include <sys/types.h>



using namespace std;

void list_dir(const char* path);
void create_list(const char* path);
bool rename(string newname);
string reverse_str(string data);
string get_type_file(string data);
string get_name();
string get_current_directory();
string INT_TO_STRING(int data);
char *STRING_TO_ARRAY_CHAR(string data);
void print_char(char *data);

