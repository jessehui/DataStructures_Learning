//单源最短路径算法

#include <iostream>
#include <algorighm>
#include <climits>	//定义有各种数据类型的最值
#include <queue>

#include "graph_ad_list.h"	//邻接表


using namespace std;

struct node{
	int id;
	int dist;
	int prev;
	bool processed;
	node: dist(INT_MAX), prev(-1), processed(false) {}
};

