/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

*/


//test very slow
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};


//Accepted good performance
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(int i = 0; i< nums.size(); i++)
        {
        	switch(nums[i])
        	{
        		case 0:
        		{red++;continue;}
        		case 1:
        		{white++;continue;}
        		case 2:
        		{blue++;continue;}
        		default: continue;
        	}
        }

        nums.clear();
        vector<int> temp1(red,0);	//init a red vector all 0
        nums.insert(nums.begin(), temp1.begin(), temp1.end());	//position, insert iterator first, insert iterator last

        vector<int> temp2(white,1);
        nums.insert(nums.end(), temp2.begin(),temp2.end());

        vector<int> temp3(blue,2);
        nums.insert(nums.end(), temp3.begin(),temp3.end());

    }
};