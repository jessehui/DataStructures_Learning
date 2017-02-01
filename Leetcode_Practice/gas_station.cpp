/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/


//not accepted. 14/16 bug

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minus_largest_residue = 0;
        int pos1;
        int largest_residue = 0;
        int pos2;
        
        int pos;
        

        int residue = 0;

        for(int i = 0 ;i < gas.size(); i++)	//get largest residue
        {
        	if(cost[i]-gas[i] > minus_largest_residue)
        	{
        		minus_largest_residue = cost[i]-gas[i];
        		pos1 = i+1;
        	}
        	
        	if(gas[i] - cost[i] > largest_residue )
        	{
        	    largest_residue = gas[i] - cost[i];
        	    pos2 = i;
        	}
        	

        }
        
        if(largest_residue >= minus_largest_residue)
            pos = pos2;
        else
            if(pos1 == cost.size())
                pos = 0;
            else
                pos = pos1;
        

        cout << "pos = " << pos << endl;

        for(int j = pos; j<gas.size(); j++)
        {
        	residue = gas[j] - cost[j] + residue;
        	if(residue < 0)
        		return -1;
        }

        for(int j = 0; j < pos; j++)
        {
        	residue = gas[j] - cost[j] + residue;
        	if(residue < 0)
        		return -1;
        }

        return pos;


    }
};

//another method	very slow
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int residue = 0;
    	int temp;
    	for(int i = 0 ;i < gas.size(); i++)
    	{
    		for(int j = i; j< gas.size()+i; j++)
    		{
    			if(j>=gas.size())
    				temp = j-gas.size();
    			else temp = j;

    			residue = residue + gas[temp] - cost[temp];
    			if(residue < 0)
    				break;
    		}
    		if(residue >= 0)
    				return i;
    		else 
    		    residue = 0;
    	}
    	return -1;


    }
};

//recommended solution
/*
***如果前面所有的gas - cost加起来小于零，那么前面所有的点都不能作为出发点。***
原因:  
首先我们是从i =0个gas station计算起的，设开始剩油量为left=0，如果这个station的油是可以到达下一个station的，
那么left=gas-cost为正数，
到了下一个station就有两种情况：
1 如果i=1个station的gas-cost也为正，那么前面的left加上当前station的剩油量也为正。
2 如果i=1个station的gas-cost为负，那么前面的left加上当前的station的剩油量也有两种情况：
一） left为正，那么可以继续到下一个station，重复前面计算i=2,i=3...，直到发生第二）种情况
二）如果left为负，那么就不能到下一个station了，这个时候如果i=k(i<k<n)，这个时候是否需要从第i=1个station开始重新计算呢？
 
 不需要，因为第k个station之前的所有left都为正的，到了第k个station才变成负。


记录最后一个加起来小于零的索引，然后返回这个索引+1就是答案了。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int pos = -1;
    	int residue = 0;	//记录所有
    	int sum = 0;	//记录到最后一个小于0的和


    	for(int i = 0 ;i < gas.size(); i++)
    	{
    		residue = residue + gas[i] - cost[i];
            sum = sum + gas[i] - cost[i];
            
    		if(sum < 0)	//不能从前边i个位置开始, 所以sum重新归零
    		{
    			pos = i;
    			sum = 0;
    		}
    	}

    	if(residue < 0)
    		return -1;
    	else
    		return (pos+1 == gas.size())?0:pos+1;

    }

};