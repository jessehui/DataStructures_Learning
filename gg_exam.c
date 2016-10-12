// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
	int left;
	int right;
    for(int i = 0; i < N; i++)
    {
    	int p = i;
    	while(p)		//compute left
    	{
    		left += A[p-1];
    		p--;

    	}
    	for(int j = N-1; j>i ; j-- )	//compute right
    		right += A[j];

    	if(right == left)
    		return i;
    	else
    	{
    		left = 0;
    		right = 0;
    	}

    }

    return -1;
}







// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include <stdlib.h>
#include <math.h>
#include <string.h>

//macro
#define CTOI(x) (x-'0')     //char to int
#define ITOC(y) (y+'0')     //int to char 

/*
func: compute the number following the rules
return: the new number (char* !)
*/
char * New_Num(int index, char *array, int size);

/*
func: compute the average and round up
return: average number (char !)
*/
char Ave_(char a, char b);


int solution(int X) {
    // write your code in C99 (gcc 4.8.2)
    
    char temp[20];
    char *array_temp;
    int max_ = 0;
    int a;
    
    sprintf(temp, "%d", X);     //convert int to char array
    int length = strlen(temp);
    
    for(int i = 0;i < length - 1;i++)
    {
        array_temp = New_Num(i, temp, length);
        a = atoi(array_temp);
        free(array_temp);
        if(a > max_)
            max_ = a;
    }
    
    return max_;
}


char * New_Num(int index, char *array, int size)
{
    char* buff = (char*)malloc(size-1);
    char temp;

    //copy the front part
    for(int i =0;i<index;i++)
        buff[i] = array[i];
   // printf("%f\n", double(array[index]));

    //get the average
    temp = Ave_(array[index], array[index+1]);
    buff[index] = temp;

    //copy the back part
    for(int i = index+2; i<size; i++)   // with respect to 'array' (original array)
        buff[i - 1] = array[i];

    //test
   // for(int i = 0;i<size-1;i++)
     //   printf("%c ", buff[i]);

    return buff;


}

char Ave_(char a, char b)
{
   // printf("Average of %c, %c\n", a, b);
    int ave = ceil( (double)( CTOI(a) + CTOI(b) )  / 2 );
    
    //int ave = ceil( (double)(( CTOI(a) + CTOI(b) )/2));
    
    
   // printf("is %d\n", ave);
    return ITOC(ave);
    
}