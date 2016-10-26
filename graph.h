#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class GraphAdMatrix{
private:
	vector<vector<int>> g;

public:
	//传进来graph的地址相当于
	GraphAdMatrix(vector<vector<int>> &g): g(g)
	{}

	void dfs_recursive(int start_node_id)
	{
		vector<bool> visited(g.size());		//g.size表示一维长度,默认都为false
		visit(visited, start_node_id);
	}


	void dfs(int start_node_id)	//深度优先, 把一个节点的所有边都遍历了再去遍历别的节点
	{
		vector<bool> visited(g.size());
		stack<int> s;	//栈存放遇到的所有节点
		s.push(start_node_id);	//先入栈一个节点
		while(s.size())
		{
			int node_id = s.top();
			s.pop();
			if(!visited[node_id])	//如果这个节点没有访问过
			{
				visited[node_id] = true;
				cout << "dfs visiting " << node_id << endl;
				for(int i=0;i<g.size();i++)
				{
					if(g[node_id][i] == 1)
						s.push(i);	//用栈替代递归
				}

			}

		}

	}

	void bfs(int start_node_id)	//广度优先就是把栈换成队列
	{
		vector<bool> visited(g.size());
		queue<int> q;
		q.push(star_node_id);
		while(q.size())
		{
			int cur_node_id = q.front();
			q.pop();
			if(!visited[cur_node_id])
			{
				visited[cur_node_id] = true;
				cout << "dfs visiting " << cur_node_id << endl;
				for(int i = 0; i < g.size(); i++)
				{
					if(g[cur_node_id][i]==1)
						q.push(i);
				}
			}

		}
	}


private:
	
	//标示哪些节点被访问过了
	void visit(vector<bool> &visited, int node_id)
	{
		visited[node_id] = true;	//把对应的node设为true
		cout << "dfs recursively visiting" << node_id << endl;
		for(int i = 0; i<visited.size(); i++)
		{	//node_id是出发点, i是目标点
			//就是要遍历所有点
			//如果不是都为1 就进入递归
			//或者看做!visited[i]表示这个节点没有被访问过
			//g[node_id][i]表示有一条边连接了node_id 和 i
			if( !visited[i] && g[node_id][i] == 1 )	
				visit(visited, i);
		}
	}


}