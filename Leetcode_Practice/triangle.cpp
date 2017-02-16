/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to !` adjacent numbers `!  on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) 
extra space, where n is the total number of rows in the triangle.


*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> result;
        for(int i = 0; i< triangle.size(); i++)
        {
        	int mini = INT_MAX;
        	for(int j = 0; j<triangle[i].size();j++)
        	{
        		if(triangle[i][j]<mini)
        			mini = triangle[i][j];
        	}
        	result.push_back(mini);

        }

        int sum = 0;
        for(auto it = result.begin(); it!=result.end(); it++)
        {
        	sum += *it;
        }

        return sum;
    }
};


//Not right 
//didn't understand the problem
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	if(triangle.size()<1 || triangle[0].size()<1)
    		return 0;

    	vector<int> pos;
    	int j = 0; 	//store the position we get the minimum value
    	pos.push_back(j);
    	
    	for(int i = 1;i<triangle.size()-1; i++)
    	{
    		int pos_temp = pos.back();
    		int mini;
    		//find the smallest value
    		// if(i>=3)	//different case: left/right most case, middle case
    		// {
    			if(pos_temp == 0)
    			{
    				j = (triangle[i+1][pos_temp] < triangle[i+1][pos_temp+1])? pos_temp:pos_temp+1;
    			}

    			else if(pos_temp == triangle[i].size()-1)
    			{
    				j = (*triangle[i+1].end()-1 < *triangle[i+1].end()-2)? triangle[i+1].size()-1:triangle[i+1].size()-2;
    			}

    			else	//middle
    			{
    				// if(triangle[i+1][pos_temp-1] > triangle[i+1][pos_temp])
    				// 	mini = triangle[i+1][pos_temp];
    				// else
    				j = (triangle[i+1][pos_temp-1] < triangle[i+1][pos_temp])?pos_temp-1:pos_temp;
    				mini = triangle[i+1][j];
					j = (mini < triangle[i+1][pos_temp+1])?j:pos_temp+1;    				
    			}

    			pos_push_back(j);

    	}

    	int sum = 0;
    	for(int i = 0; i < pos.size(); it++)
    	{
    		cout << "smallest value = " << triangle[i][pos[i]] << endl;
    		sum = sum + triangle[i][pos[i]];
    	}
    }
};

//recommended solution
//bottom up method
//O(n) space
int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n-2; layer >= 0; layer--) // For each layer
    {
        for (int i = 0; i <= layer; i++) // Check its every 'node'
        {
            // Find the lesser of its two children, and sum the current value in the triangle with it.
            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
        }
    }
    return minlen[0];


//another try
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int level = triangle.size();
        //bottom up
        vector<int> result = triangle[level-1];
        for(int i = level-2; i>=0; i--)
        {
        	for(int j = 0; j < triangle[i+1].size()-1; j++) 
        	{
        		result[j] = min(result[j], result[j+1]) + triangle[i][j];
        	//	cout << "result[0] = " << result[0] << endl;
        	}
        }

        return result[0];	//because in the top level, there is the only element
    }
};

