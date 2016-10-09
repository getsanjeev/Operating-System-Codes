#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>

using namespace std;

int main()
{
	char* buff;
	buff = getcwd( buff, PATH_MAX + 1 );
	if( buff != NULL ) {
        cout<<buff;
    }   
    cout<<"cdbn" ;

  	/*string newDir;  
    cout<<"enter value"  <<endl;
    cin>>newDir;
    int rc = chdir(newDir.c_str());
    if (rc < 0) 
    {     
    	cout<<rc;  
    }
    else
    {
    	buff = getcwd( buff, PATH_MAX + 1 );
		if( buff != NULL ) {
		cout<<buff;       
    }
    }*/
   

}

