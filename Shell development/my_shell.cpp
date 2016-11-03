#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<unistd.h>

using namespace std;

void change_directory(string directory);
void get_current_directory_info();
string strtrim(string sentence);
vector<int> get_white_spaces(string sentence);
vector<string> tokenizer(string sentence);
void get_current_directory_info();



// cd directory path: change directory
// currentdir: gives the current directory path
int main()
{	
	string command;
	cout<<"Welcome to the new SHELL"<<endl;
	int a = 1;			
	cout<<"Sanjeev@hpProBook~$";
	getline(cin, command);
	vector<string> tokens = tokenizer(command);
	string my_commands [2] = {"cd", "currentdir"};
	int number;
	for(int i = 0;i<2;i++)
	{
		if(tokens[0] == my_commands[i])
		{			
			number = i;
			break;
		}
	}
	switch(number)
	{
		case 0: change_directory(tokens[1]);
				break;
		case 1: get_current_directory_info();
				break;
		case 2: //	
		break;			
	}
}



void change_directory(string directory)
{
    int status = chdir(directory.c_str());
    if(status != 0) cout<<"ERROR: no directory found";    
}

void get_current_directory_info()
{	
	char *cmd = NULL;
    cmd = get_current_dir_name ();
    cout<<"Directory changed to: "<<cmd<<endl;    
}

vector<string> tokenizer(string sentence)
{
	int p;
	sentence = strtrim(sentence);	
	vector<string> tokens (10);		
	vector<int> index_vector = get_white_spaces(sentence);	
	int pre,post,length,i;
	i= 0;
	length = 0;
	string temp;
	while(i < index_vector.size())
	{
		if((i ==0)||(index_vector.at(i) !=0))
		{
			temp.clear();
			pre = index_vector.at(i);
			post = index_vector.at(i+1);			
			for(int j = pre;j<=post;j++)
			{
				temp = temp + sentence[j];
			}			
			tokens.at(length) = temp;
			length++;		
		}

		i = i+2;
	}	
	return tokens;
}
vector<int> get_white_spaces(string sentence)
{	
	vector<int> space_index(20);
	char x;
	int i = 0;
	int j,k;
	k = 0;
	int diff = 0;	
	space_index.at(k) = 0;
	k++;
	while(i<sentence.size())
	{		
		if(sentence[i] == ' ')
		{
			space_index.at(k) = i-1;
			k++;
			j = i;
			while(j<sentence.size()-1)
			{				
				if((sentence[j]==' ')&&(sentence[j+1]!=' ')) 
				{			
					space_index.at(k) = j+1;
					k++;
					break;
				}
				else j++;
			}						
			diff = j-i;
			i = j+1;			
		}	
		else i++;			
		 
	}
	space_index.at(k) = sentence.size()-1;	
	return space_index;
}

string strtrim(string sentence)
{	
	int i = 0;
	sentence = sentence.c_str();
	int j = sentence.size()-1;	
	char x;		
	while(i < j)
	{
		if(sentence[0] != ' ') 
		{
				i = 0;
				break;
		}
		else if((sentence[i] == ' ') && (sentence[i+1] != ' ')) 
		{
				i = i+1;
				break;
		}
		else
		{
			i++;			
		}
	}	
	while(j>0)
	{
		if(sentence[sentence.size()-1] != ' ') break;		
		else if((sentence[j] == ' ') && (sentence[j-1]!=' ')) 
		{	
			j = j-1;
			break;
		}
		else j--;
	}
	string trm_str;
	trm_str.clear();	

	for(int k = i; k<=j; k++)
	{
		x = sentence[k];
		trm_str = trm_str + x;		
	}	
	return trm_str;

}

