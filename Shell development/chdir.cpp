#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

using namespace std;
int main()
{
    char* cwd;
    char buff[PATH_MAX + 1];

    cwd = getcwd( buff, PATH_MAX + 1 );
    if( cwd != NULL ) {
        printf( "My working directory is %s.\n", cwd );
    }

    string newDir;    
    scanf("enter the directory", newDir)
    int rc = chdir(newDir.c_str());
    if (rc < 0) {       
    }

    else
    {
    	cwd = getcwd( buff, PATH_MAX + 1 );
    if( cwd != NULL ) {
        printf( "My working directory is %s.\n", cwd );
    }

    }

    return EXIT_SUCCESS;
}