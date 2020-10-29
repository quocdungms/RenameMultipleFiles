
#include "file.h"
using namespace std;

int main()
{
	
	///* 
	//*
	//* 
	//*/
	//printf("---------- Thor tool ----------\n");
	//printf("1. Change multiple file name\n");
	//printf("Enter yout choose: ");
	//int choose;
	//cin >> choose;

	//switch (choose)
	//{
	//case 1:
	//{
	//	string directory;
	//	printf("Import your file directory: ");
	//	getline(std::cin, directory);
	//	
	//	
	//	/*string name;
	//	name = get_name();
	//	const char* trans = directory.c_str();
	//	filename_to_list(trans);
	//	change_name();*/
	//}

	//default:
	//	break;
	//}
	printf("*************************************************\n");
	printf("*             Rename multiple files             *\n");
	printf("*                  Made by Thor                 *\n");
	printf("*******************************************\n");
	printf("Notice:\n");
	printf("1. Create a new folder\n");
	printf("2. Put program and your files into new folder\n");
	printf("3. Run again!\n\n");
	printf("New file name will have title: Newname1.xxx, Newname2.xxx ...\n");
	printf("Enter new file name: ");
	string new_name;
	getline(std::cin, new_name);
	string directory;
	directory = get_current_directory();
	const char* trans = directory.c_str();
	//cout << directory;
	create_list(trans);
	if (rename(new_name))
		printf("Renamed successfull!!!\n");
	else
	{
		printf("Fail to rename file!!!\n");
		printf("Please check your directory of program!!!\n");
	}

	//filename_to_list(STRING_TO_ARRAY_CHAR(d));
	//system("pause");
	return 0;
}