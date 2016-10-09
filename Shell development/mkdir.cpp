#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

void change_directory(string directory);
void open_file(string file_name);
void get_data_string(string file_name);

int main()
{
    char *cmd = NULL;
    cmd = get_current_dir_name ();
    cout<<"my cr d is"<<" "<<cmd<<endl;
    /*char* buff;
    buff = getcwd( buff, 20 );    
    if( buff != NULL ) {
        cout<<buff;
    }*/
    string f1,f2;
    /*cout<<"enter file name"<<endl;
    cin>>f1;
    get_data_string(f1);
    
    cout<<"sxb";*/
    string dir;
    cout<<"Entr directory"<<endl;
    getline(cin,dir);
    change_directory(dir);

    cmd = get_current_dir_name ();
    cout<<"my cr d is"<<" "<<cmd<<endl;

    cout<<"enter file name"<<endl;
    cin>>f2;
    get_data_string(f2);


    

}

void change_directory(string directory)
{
    int a = chdir(directory.c_str());
    cout<<a;     
}


void get_data_string(string file_name)
{
    cout<<"in function"<<endl;
    ifstream file(file_name.c_str());
    string word;
    char x ;
    word.clear();
    int count  = 0;
    while ((x = file.get())!= EOF)
    {
        cout<<x;
        word = word + x;
    }
    file.close();
    cout<<"ncdjbjb";
}

void get_directory_info()
{
    
}
