#include <iostream>
using namespace std;
//find if there is a corresponding demanded string(target) in the given string

int find_str(char* target, char *given)
{
  //  int pos;    //position first have a match
    int match_num = 0;  //number of matching char (not matching string)
    for(int i = 0; i< strlen(given); i++)
    {
        for(int j = 0; j<strlen(target);j++)
        {
            if(target[j] == given[i+j])
                match_num++;
        }
        printf("match number is %d\n", match_num);
        if(match_num == strlen(target))
            return i;
        else
            match_num = 0;
        
        
            
    }
    
    return -1;
        
}


int main()
{
	char *target_string = new char[10];
	char *given_string = new char[100];
	cout << "Please input a target string : ";
	cin >> target_string;
	cout << "Please input a string to find from : ";
	cin >> given_string;
    
    int position;
    position = find_str(target_string, given_string);
    cout << "the first time it appears is at position " <<position << endl;
    
    return 0;
    
}

