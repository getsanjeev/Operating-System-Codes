#include<iostream>
#include<string.h>
using namespace std;

struct SimpleCommand
{
	int number_of_available_arguments;
	int number_of_arguments;
	char **arguments;		//array of arguments
	SimpleCommand();
	void insert_argument(char *argument);
};

struct Command
{
	int no_of_available_simple_commands;
	int number_of_simple_commands;
	simpleCommand **simpleComamnds;
	char *outFile;
	char *inputFile;
	char *errFile;
	int background;

	void prompt();
	void print();
	void execute();
	void clear();

	Command();
	void insertSimpleCommand(SimpleCommand * simpleCommand);
	static Command currentCommand;
	static SimpleCommand *currentSimpleCommand;

};


int main()
{
	
}