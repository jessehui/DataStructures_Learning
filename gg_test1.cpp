//一个数字里面任选相邻两位数，保留较大的，返回可能的结果中最小的那个数。比如233614就返回23364。
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define CTOI(x) (x - '0')
#define ITOC(y) (y+'0')

char * New_Num(int index, char * array, int size);
char * New_Num2(int index, char *array, int size);

int Max_(int a, int b)
{
    return (a>b)?a:b;
}

char Ave_(char a, char b)
{
    printf("Average of %c, %c\n", a, b);
    int ave = ceil( (double( CTOI(a) + CTOI(b))) / 2 );
    printf("is %d\n", ave);
    return ITOC(ave);
    
}

int main()
{
    int num;
    char temp[32];
    unsigned int a;
    int i;
    
    char *array_temp;
    scanf("%d", &num);  //get the number
    // num = 7141;
    int min = num;
    sprintf(temp, "%d", num);   //convert int to char array
    int length = strlen(temp);
    printf("length = %d\n", length);
    for(i = 0;i < length - 1;i++)
    {
        array_temp = New_Num2(i, temp, length);
        a = atoi(array_temp);
        free(array_temp);
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

//是把两个数字换成平均数，向上取整，使结果最大
char * New_Num2(int index, char *array, int size)
{
    char* buff = (char*)malloc(size-1);
    char temp;

    for(int i =0;i<index;i++)
        buff[i] = array[i];
   // printf("%f\n", double(array[index]));

    temp = Ave_(array[index], array[index+1]);
    buff[index] = temp;

    for(int i = index+2; i<size; i++)   //相对于array数组(原数组)
        buff[i - 1] = array[i];

    for(int i = 0;i<size-1;i++)
        printf("%c ", buff[i]);

    return buff;


}

// 在C语言中,char的数据类型可以看作是8位的整型数类型;

// 例如: char c = 'a';

// 将c当作整型数,实际上它的值就是'a'的ASCII编码, 十进制为 97.

// 如果要把c转换成double类型,实际上就是将整型数97转换成double类型.
// 例如:
//    double  d = (char)c;

// 这个时候,d的值为 97.00000.

// 实际应用中, 还有一种转换就是将字符串转换成double的数据.
// 例如:

// char *s = "1234.56";

// 这需要用atof函数进行转换:

// double d = atof(s);







