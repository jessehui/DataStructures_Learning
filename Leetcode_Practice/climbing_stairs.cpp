/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct
 ways can you climb to the top?

Note: Given n will be a positive integer.

*/

//not right
class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways_for_cor_stairs(n, 1);	//到每一级都可以从之前的一级通过一种方法上来
        int result = 0;
        for(int i = 2; i < n; i++)	//从第二级开始, 每一级还能直接从之前两级通过一种方法上来
        {
        	ways_for_cor_stairs[i]++;
        }

        for(int i = 1; i < n; i++)
        {
        	result = ways_for_cor_stairs[i] + result;
        }
        
        if(n<=1)
            result++;

        return result;

    }
};

// recursive solution TLE
class Solution {
public:
    int climbStairs(int n) {
  		if(n == 2)
  			return 2;
  		if(n == 1)
  			return 1;

  		return  climbStairs(n-2)*1 + climbStairs(n-1)*1 ;

    }
};

//dp solution
// Accepted
class Solution {
public:
    int climbStairs(int n) {
  	if(n < 1)
  		return 1;
  	if(n == 2)
  		return 2;

  	vector<int> ways_for_cor_stairs(n+1, 1);	//到每一级都可以从之前的一级通过一种方法上来
  	for(int i = 2; i<=n; i++)
  	{
  		ways_for_cor_stairs[i] = ways_for_cor_stairs[i-1] + ways_for_cor_stairs[i-2];
  	}

  	return ways_for_cor_stairs[n];


    }
};
