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

//another method	
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