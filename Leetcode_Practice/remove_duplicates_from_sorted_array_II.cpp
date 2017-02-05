/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of 
nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave
 beyond the new length.
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> num_times;	//number times

        for(int i = 0; i< nums.size(); i++)
        {
        	if(!num_times.count(nums[i]) || num_times[nums[i]] < 2)	//if not in hash map or no more than 2 times
        	{
        	    
        		result.push_back(nums[i]);
        		num_times[nums[i]]++;
      //  		cout << "nums[i] = " << nums[i] << " ";
        	}

        	else	//if in
        	//	if(num_times[nums[i]] >= 2)	// more than two 
        		{
        //		    cout << "GO" <<endl;
        		   // i++;
        			continue;
        			
        		}

        // 	else
        // 		cout << "WHY HERE???" <<endl;

        }
        nums = result;
        return (int)result.size();
    }
};


