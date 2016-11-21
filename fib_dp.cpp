#include <iostream>

//fib: 		0 1 1 2 3 5 8 13 ...
//index:	0 1 2 3 4 5 6  ...

using namespace std;

int fib_rec(int times)
{
	if(times < 2)
		return times;
	else
		return fib_rec(times-1) + fib_rec(times-2);
}

unsigned long long fib_dp(int n)
{
	if(n < 2)
		return n;

	unsigned long long *value_table = new unsigned long long [n+1];	//0..n共n+1个元素
	value_table[0] = 0;
	value_table[1] = 1;
	for(int i = 2; i <= n; i++) //比如n=2,要加到2的, 所以是 i<=n
		value_table[i] = value_table[i-1] + value_table[i-2];

	return value_table[n];
}




int main()
{
	for(int i = 0; i < 50; i++)
	{
		cout << fib_dp(i) << endl;//打印第i个数
	}
}
