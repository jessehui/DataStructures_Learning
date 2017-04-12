/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.

*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ = INT_MAX , max_ = 0;
        int max_pro = 0;

        int i = 1;
        
	    while(i < prices.size())
	    {
	    	while(prices[i-1] >= prices[i])
	    	{	
	    		i++;
	    		if(i == prices.size())
	    			return max_pro;
	    	}

	    	//local min
	    	if(prices[i-1] < min_)
	    	{
	    		min_ = prices[i-1];
	    		i++;
	//    		cout << "min_ = " << min_ << endl;
	    	}


	    	//find local max
	    	while(i < prices.size() && prices[i-1] <= prices[i])
	    	{
	    		i++;
	    		// if(i == prices.size())
	    		// 	break;
	    	}
	    	//local max
	    	if(prices[i-1] - min_ > max_pro)
	    	{
	    		max_pro = prices[i-1] - min_;
	    		i++;
	    //		cout << "max_pro = " << max_pro << endl;
	    	}

	    }

	    return max_pro;
    }
    
};





