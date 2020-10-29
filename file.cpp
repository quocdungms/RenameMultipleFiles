#include "file.h"


string reverse_str(string data)
{
    string redata = data;
    int size = data.length();
    for (int i = 0; i < size / 2; i++)
    {
        swap(redata[i], redata[size - i - 1]);
    }
    return redata;
}
string get_type_file(string data) 
{
    string temp = reverse_str(data);
    string delimiter = ".";
    string token;
    size_t pos = 0;
    while ((pos = temp.find(delimiter)) != std::string::npos) {
        token = temp.substr(0, pos+1);
        temp.erase(0, pos + delimiter.length());
    }

    return reverse_str(token);
}
string get_current_directory()
{
    char buff[PATH_MAX];
    _getcwd(buff, PATH_MAX);
    string temp(buff);
    return temp;
}

string get_name() 
{
    printf("Enter the name you want to change: ");
    string name;
    getline(cin, name);
    return name;
}
void print_char(char *data)
{
    for (int i = 0; i < sizeof(data); i++)
        cout << data[i];

}
string INT_TO_STRING(int data)
{
    string snumber;
    ostringstream convert;
    convert << data;
    return snumber = convert.str();
}
char *STRING_TO_ARRAY_CHAR(string data)
{

     char* arr = new char[data.length() + 1];
    for (int x = 0; x < sizeof(arr); x++) 
    {
        arr[x] = data[x];
    }
    return arr;
}



void list_dir(const char* path) {
    struct dirent* entry;
    DIR* dir = opendir(path);

    if (dir == NULL) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        cout << entry->d_name << endl;
    }
    closedir(dir);
}
void create_list(const char* path)
{
    fstream _file;
    
    _file.open("list.txt", ios::out);
    if (_file.fail())
        cout << "Fail to open file!!!\n";


    struct dirent* entry;
    DIR* dir = opendir(path);

    if (dir == NULL) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        _file << entry->d_name << endl;
    }
    closedir(dir);

    _file.close();
}

bool rename(string newname)
{
    fstream _file;
    _file.open("list.txt", ios::in);
    if (_file.fail())
    {
        cout << "Fail to open file!!!\n";
        return false;
    }
     
    /*string cd_path;
    cd_path = "cd \""+ path + "\"";
    string repair_cd = "D:";*/
    fstream ot;
    ot.open("command.txt", ios::out);
    if (ot.fail())
    {
        cout << "Fail to write file!!\n";
        return false;
    }

    
    int number = 1;
    

    string temp;
    string line;
    while (!_file.eof())
    {
        //// int to string
        //string snumber;
        //ostringstream convert;
        //convert << number;
        //snumber = convert.str();


        getline(_file, line);

        temp = "REN \"" + line + "\""
            + " "
            + "\"" + newname + INT_TO_STRING(number) + get_type_file(line) + "\"";
        number++;
        ot << temp << endl;
        //system("D:\\Program Files\\Atom\\AAAAAAA");
       // system(temp.c_str());
        system(temp.c_str());
        
    }
    _file.close();
    ot.close();
   // system("cls");
    remove("list.txt");
    remove("command.txt");
    return true;


}