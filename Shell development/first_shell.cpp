#include<iostream>
#include<string.h>
using namespace std;

#define LSH_RL_BUFSIZE 1024

int main()
{
	lsh_loop();
}

void lsh_loop()
{
  string input_string;
  vector<string> args;
  int status;

  do {
    printf("> ");
    input_string = lsh_read_line();	
    args = tokenize_input(input_string);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

string lsh_read_line(void)
{
  string input_string;
  getline(cin, input_string);  
  return input_string;
}

int lsh_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) 
  {
    // Child process
    if (execvp(args[0], args) == -1) 
    {
      perror("lsh");
    }

    exit(EXIT_FAILURE);
  } 
  else if (pid < 0) 
  {
    // Error forking
    perror("lsh");
  } 
  else 
  {
    // Parent process
    do 
    	{
      		wpid = waitpid(pid, &status, WUNTRACED);
    	} 
    while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

vector<string> tokenize_input(string sentence)
{
	vector<string> token_vector;			
	int size_sentence = sentence.size();	
	char tab2[size_sentence+1];	
	tab2[size_sentence+1] = '\0';
	strcpy(tab2, sentence.c_str());		
	int pre_index = 0;
	int post_index = 0;	
	vector<int> index_vector = KMP_implementation(sentence, " ");	
	index_vector.push_back(size_sentence-1);
	//cout<<"size of vector is "<<index_vector.size()<<endl;	
	string temp;
	string tokens[(index_vector.size())/2];	
	int p = 0;
	int m = 0;
	while(m<= index_vector.size()-2)
	{
		int temp_size = index_vector[m+1] - index_vector[m] + 1;			
		char arr[temp_size];
		int start = p;
		for(int k = 0;k<temp_size;k++)
		{									
			arr[k] = tab2[start];			
			start++;
		}		
		temp = arr;				
		m = m+2;	
		p = index_vector[m];	
	}	
	token_vector.push_back(temp);
	vector<string>::iterator it;
    for(it = token_vector.begin();it!= token_vector.end();++it )
    {
    	cout<< *it<<"   bhghsanjevhh";
    }
	return token_vector;
}

vector<int> KMP_implementation(string text_string, string pattern_string)   //This is implementation of KMP algorithm
{	vector<int> v;
	v = search_substring(text_string, pattern_string);
	return v;
}

vector<int> search_substring(string text_string, string pattern_string)
{
	vector<int> index_vector;
	index_vector.push_back(0);
	int pattern_len, text_len, j, i,count;
	count  = 0;
	pattern_len = pattern_string.length();
	text_len = text_string.length();
	int pmt[pattern_len];
	j = 0;
	get_partial_match_table(pattern_string, pattern_len, pmt);
	i = 0;
	while (i < text_len)
	{
		if (pattern_string[j] == text_string[i])
		{
			j = j+1;
			i = i+1;
		}
		if (pattern_len == j)
		{			
			index_vector.push_back(i-j-1);
			index_vector.push_back(i-j+1);
			count = count +1;
			j = pmt[j-1];
		}
		else if ((i < text_len)&&(pattern_string[j] != text_string[i]))
		{
			if ( 0 != j)
			{
				j = pmt[j-1];
			}
			else
			{
				i = i + 1;
			}
		}
	}
	return index_vector;   //returns no of times a pattern is contained in it.
}

void get_partial_match_table(string pattern_string, int pattern_len, int pmt[])
{
	int j = 0;
	int i = 1;
	pmt[0] = 0;
	while (i < pattern_len)
	{
		if (pattern_string[i] == pattern_string[j])
		{
			pmt[i] = j+1;
			j++;
			i++;
		}
		else
		{
			if (0 != j)
			{
				j = pmt[j - 1];
			}
			else
			{
				pmt[i] = 0;
				i++;
			}
		}
	}
}
