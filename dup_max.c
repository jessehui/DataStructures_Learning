//给一个数字，比如12345,可以duplicate任意一位，
//比如第一位就得到112345第二位就得到122345，
//以此类推，然后求这些duplicate中最大的
// a number give, e.g. 12345, duplicate any bit and get a new number
//for example duplicate the first bit we get 112345. dupliacate the second bit we get 122345
//find the biggest number among al the new number after dupliacting

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * duplicate(int index, char * array, int size);

int main()
{
    int num;
    char temp[32];
    unsigned int max = 0;
    unsigned int a;
    int i;
    scanf("%d", &num);  //get the number
    // num = 7141;
    sprintf(temp, "%d", num);   //convert int to char array
    int length = strlen(temp);
    printf("length = %d\n", length);
    for(i = 0;i < length;i++)
    {
        a = atoi( duplicate(i, temp, length));
        printf("a = %d\n", a);
        if(a>max)
            max = a;
    }
    printf("The biggest number is %d\n", max);
    
    return 0;
}

char * duplicate(int index, char * array, int size)
{
    char *tmp = (char*)malloc(size+1);
    //bug when use char* tmp[size+1];
    //The local variables have a lifetime which
    //extends only inside the block in which it is
    //defined. The moment he control goes outside the
    // block in which the local variable is defined, the
    //storage for the variable is no more allocated (not guaranteed).
    
    int i,j;
    for(i = 0;i <= index; i++)
        tmp[i] = array[i];      //copy the same number
    
    tmp[index+1] = array[index];    //duplicate the index value
    
    for(j = index + 1; j < size + 1; j++)
        tmp[j+1] = array[j];        //copy the rest
    
    // printf("tmp: ");
    // for(int i=0;i < size+1;i++)
    //     printf("%c  ", tmp[i]);
    // printf("\n");
    
    return tmp;
    
    
}

