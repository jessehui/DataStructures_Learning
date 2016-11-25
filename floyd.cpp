//是解决任意两点间的最短路径的一种算法
//可以正确处理有向图或负权（但不可存在负权回路)的最短路径问题，同时也被用于计算有向图的传递闭包。
//利用不断更新邻接矩阵解决


#include <iostream>
#include <vector>
#include <climits>


using namespace std;

//&表示在函数中对参数的改变会影响到函数外
//形参可以是任何名字, 并不一定要和主函数中定义的变量同名
void print_path(vector<vector <int>> &next_test, int i, int j)
{
	cout << "Printing path from " << i << " to " << j << " : ";
	if(next_test[i][j] == -1)
	{
		cout << "no path found" << endl;
		return;
	}
	cout << i;
	while(i != j)
	{
		i = next_test[i][j];
		cout << "->" << i;
	}
	cout << endl;
}

int main()
{
	//init 所有点之间距离 9999表示未联通
	vector<vector<int>> d = {
		{0, 9999, -2, 9999},
		{4, 0, 3, 9999},
		{9999, 9999, 0, 2},
		{9999, -1, 9999, 0}
	};

	//用0,1,2,3表示4个节点, -1表示无同路或者是自身
	//二维表示从a_node到b_node
	//next[i][j]: 从i到j, 如果有通路(比如i->a->c->j), 那么表示从i出发的下一个节点(a)
	//如果不经过别的节点, 那么就是j. 如果没有同路,那就是-1
	vector<vector<int>> next {
		{-1, -1, 2, -1},
		{0, -1, 2, -1},
		{-1, -1, -1, 3},
		{-1, 1, -1, -1}
	};

	for(int k = 0; k < d.size(); k++)
		for(int i = 0; i < d.size(); i++)
			for(int j = 0; j < d.size(); j++)
			{
				if(d[i][j] > d[i][k] + d[k][j])	//任意两点的距离大于经过第三点的距离只和,就更新邻接矩阵
				{
					d[i][j] = d[i][k] + d[k][j];
					next[i][j] = next[i][k];//为了最短路, 本来i下一个是j的, 现在替换成k了
				}
			}


	//打印所有点之间的距离
	for(int i = 0; i < d.size(); i++, cout << endl)
		for(int j = 0;j< d.size();j++)
			cout << d[i][j] << " ";

	for(int i = 0; i < d.size(); i++, cout << endl)
		for(int j = 0;j< d.size();j++)
			print_path(next, i, j);

	return 0;

}

