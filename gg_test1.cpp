//一个数字里面任选相邻两位数，保留较大的，返回可能的结果中最小的那个数。比如233614就返回23364。
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * New_Num(int index, char * array, int size);

int Max_(int a, int b)
{
    return (a>b)?a:b;
}

int main()
{
    int num;
    char temp[32];
    unsigned int a;
    int i;
    scanf("%d", &num);  //get the number
    // num = 7141;
    int min = num;
    sprintf(temp, "%d", num);   //convert int to char array
    int length = strlen(temp);
    printf("length = %d\n", length);
    for(i = 0;i < length - 1;i++)
    {
        a = atoi( New_Num(i, temp, length));
        printf("a = %d\n", a);
        if(a<min)
            min = a;
    }
    printf("The smallest number is %d\n", min);
    
    return 0;
}

char * New_Num(int index, char * array, int size)
{
	char *buff = (char*)malloc(size-1);	//减了一位
	char temp;

	//复制index前的到buff
	for(int i =0;i<index;i++)
		buff[i] = array[i];

	//从相邻两位选最大的
	temp = Max_(array[index], array[index+1]);
	buff[index] = temp;

	//复制后边的到buff
	for(int i = index+2; i < size; i++)
		buff[i-1] = array[i];
    
    for(int i = 0;i<size-1;i++)
        printf("%c ",buff[i]);

	return buff;
    	
    
    
}



