/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many 
transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

Method: 

You make profit by buying low and selling high, 
so a person would buy at trough and sell at crest, 
here the subtle thing is it is equivalent to buying at i and selling 
at i + 1 as long as price is increasing, this is fine because you can 
do as many transactions as you want.

Suppose the prices are

1  2  3  4  5
then 5 - 1 == 2 - 1 + 3 - 2 + 4 - 3 + 5 - 4


*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        if(prices.size()<1)
            return max_profit;
        for(int i = 0; i<prices.size()-1; i++)
        {
        	if(prices[i+1]>prices[i])
        		max_profit = prices[i+1] - prices[i] + max_profit;
        }
        return max_profit;
    }
};