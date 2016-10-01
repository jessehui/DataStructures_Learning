//
//  joseph_array.cpp
//  datastucture_test
//
//  Created by Jesse. on 9/30/16.
//  Copyright © 2016 Jesse. All rights reserved.
//


#include <iostream>
class joseph_circle{
	int * next_persons;	// array of indexes of next person
	int circle_length;
	int tail;

public:
	joseph_circle(int circle_length) : circle_length(circle_length){	//构造函数继承?
		//初始化
		next_persons = new int[circle_length];
		for(int i = 0;i < circle_length; i++)
		{
			next_persons[i] = (i+1) % circle_length;	//points to next person in the circle
		}
		tail = circle_length - 1;
	}

	void eliminate(int step)
	{
		int p = tail;
		while(next_persons[p] != p)	//more than one element in the circle
		{
			for(int i = 0;i < step - 1;i++)
			{
				p = next_persons[p];	//一直向前走, 到要删除的节点的前一个
			}

			int eliminated_node = next_persons[p];	//eliminate the next one
			next_persons[p] = next_persons[next_persons[p]];	//重新连接节点
			if(eliminated_node == tail)
				tainl = p;	//update tail
			std::cout << "deleting: " << eliminated_node << std::endl;
			output();
		}
	}

	void output()
	{
		int p = tail;
		while(true)
		{
			p = next_persons[p];
			std::cout << p << " ";
			if(p == tail)
				break;
		}
		std::cout << std::endl;
	}

}; //end of class definition

int main()
{
	joseph_circle circle(6);

	circle.eliminate(3);	//eliminate using a step of 3
	return 0;
}

