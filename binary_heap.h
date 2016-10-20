#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class binary_heap{
	vector<T> data;

protected: //protected成员可以被派生类对象访问，不能被用户代码（类外）访问。
	virtual bool compare(T a, T b) = 0;	//纯虚函数

public:
	void insert(T value)
	{
		data.push_back(value);	//在末尾插入一个元素
		int pos = data.size() - 1;	//最后一个index
		while(pos > 0)
		{
			int parent = (pos - 1) / 2;	//parent对应的index
			if(parent < 0 || !compare(value, data[parent]))	//parent index < 0 或者不符合堆父子节点的规则
				{break;}	//例如对于root为最大的heap, 如果new value > parent就表示不符合堆的规则, 就要交换. 
			swap(data[pos], data[parent]);	//交换父子节点位置
			pos = parent;

		}
		dump();
	}

	T root()
	{
		return data[0];
	}

	//delete the root of the heap
	void delete_root()
	{
		data[0] = data.back();	//传回最后一个元素
		data.pop_back(); 	//删除最后一个元素
		heapify(0);		//堆重排
		return;

	}

	bool empty()
	{
		return data.empty();
	}

	int size()
	{
		return data.size();
	}

	void dump()	//遍历打印所有点
	{
		for(int i = 0; i < data.size(); i++)
			cout << data[i] << " ";
		
		cout << endl;
	}


private:
	void heapify(int pos)	//堆化
	{
		dump();
		int left = 2 * pos + 1;		//左边子节点的index
		int right = 2 * pos + 2;	//右边子节点的index
		int largest_pos = pos;		//极大值或者极小值, 这里用极大值代替

		//取得三个数中最大的数
		if(left < data.size() && compare(data[left], data[largest_pos])) 
			largest_pos = left;
		if(right < data.size() && compare(data[right], data[largest_pos]))
			largest_pos = right;

		//如果不是顶点 下边的堆就被破坏了 就要重新堆化
		if(largest_pos != pos)
		{
			swap(data[pos], data[largest_pos]);
			heapify(largest_pos);	//递归调用, 对下边的堆重排
		}

	}




};


template <typename T>
class max_binary_heap : public binary_heap<T>{	//一个模板类继承另一个模板类
protected:
	virtual bool compare(T a, T b)	//a>b则为真
	{
		return a > b;
	}
};

template <typename>
class min_binary_heap : public binary_heap<T>{
protected:
	virtual bool compare(T a, T b)	//a < b则为真
	{
		return a < b;
	}
}






