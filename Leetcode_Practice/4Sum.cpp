
//Accepted 但是太繁琐 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> result;
    vector<vector<int>> final_result;
    unordered_set<int> hash_set;
  //  unordered_set<vector<int>> check_repeat;

    
    if(nums.size() == 4 && target == nums[0]+nums[1]+nums[2]+nums[3])
    {
        final_result.push_back(nums);
        return final_result;
    }
    else
    if(nums.size() < 4)
        return final_result;
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size();i++)
    {
        for(int j = i+1; j< nums.size();j++)
        {
            for(int k = j+1; k < nums.size();k++)
            {
                if(k==j || k == i || i==j)
                    continue;
                if(hash_set.count(target-nums[i]-nums[j]-nums[k])==1)   //count return only 0 or 1
                {
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    result.push_back(nums[k]);
                    result.push_back(target-nums[i]-nums[j]-nums[k]);
                    sort(result.begin(),result.end());
                    if(find(final_result.begin(),final_result.end(),result) == final_result.end())
                    {
                        final_result.push_back(result);
                        result.clear();
                    }
                    else
                        result.clear();
                }
                
            }
        }
        hash_set.insert(nums[i]);
    }
    
    return final_result;
}
};




//new method 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;

        vector<int> temp;
        unordered_set<int> hash_set;
        sort(nums.begin(),nums.end());

        for(int i = 0; i<nums.size(); i++ )
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<nums.size(); j++)
            {
                if(j != i+1 && nums[j] == nums[j-1])
                    continue;
                for(int k = j+1; k < nums.size(); k++)
                {
                    int fourth = target-nums[i]-nums[j]-nums[k];
                    if(hash_set.count(fourth))
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(fourth);
                        temp.push_back(nums[k]);
                        if(result.size() == 0 || result.back() != temp)
                            result.push_back(temp);

                        temp.clear();
                    }
                    hash_set.insert(nums[k]);
                }

                hash_set.clear();
            }

        }

        return result;

        }
};

//another way : use set(no repeat element)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;

        vector<int> temp;
        unordered_set<int> hash_set;
        set<vector<int>> set;
        sort(nums.begin(),nums.end());

        for(int i = 0; i<nums.size(); i++ )
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<nums.size(); j++)
            {
                if(j != i+1 && nums[j] == nums[j-1])
                    continue;
                for(int k = j+1; k < nums.size(); k++)
                {
                    int fourth = target-nums[i]-nums[j]-nums[k];
                    if(hash_set.count(fourth))
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(fourth);
                        temp.push_back(nums[k]);
                        
                        set.insert(temp);

                        temp.clear();
                    }
                    hash_set.insert(nums[k]);
                }

                hash_set.clear();
            }

        }
        if(set.size()<1)
            return result;

        for(auto it = set.begin(); it != set.end(); it++)
        {
            result.push_back(*it);
        }

        return result;

        }
};

//
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> result;
    vector<vector<int>> final_result;
    unordered_set<int> hash_set;
  //  unordered_set<vector<int>> check_repeat;
    set<vector<int>> temp;

    
    if(nums.size() == 4 && target == nums[0]+nums[1]+nums[2]+nums[3])
    {
        final_result.push_back(nums);
        return final_result;
    }
    else
    if(nums.size() < 4)
        return final_result;
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<nums.size();i++)
    {
        for(int j = i+1; j< nums.size();j++)
        {
            for(int k = j+1; k < nums.size();k++)
            {
                if(k==j || k == i || i==j)
                    continue;
                if(hash_set.count(target-nums[i]-nums[j]-nums[k])==1)   //count return only 0 or 1
                {
                    result.push_back(target-nums[i]-nums[j]-nums[k]);
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    
                    result.push_back(nums[k]);
                    
                    //sort(result.begin(),result.end());
                    temp.insert(result);
                }
                
            }
        }
        hash_set.insert(nums[i]);
    }
    if(temp.size()<1)
            return final_result;

    for(auto it = temp.begin(); it != temp.end(); it++)
    {
        final_result.push_back(*it);
    }


    
    return final_result;
}
};


//not AC TLE
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;

        vector<int> temp;
        unordered_set<int> hash_set;
        sort(nums.begin(),nums.end());

        for(int i = 0; i<nums.size(); i++ )
        {
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<nums.size(); j++)
            {
                if(j != i+1 && nums[j] == nums[j-1])
                    goto hash_;
                for(int k = j+1; k < nums.size(); k++)
                {
                    int fourth = target-nums[i]-nums[j]-nums[k];
                    if(hash_set.count(fourth))
                    {
                        
                        temp.push_back(nums[i]);
                        temp.push_back(fourth);
                        temp.push_back(nums[j]);
                        
                        temp.push_back(nums[k]);
                        if(result.size() == 0 || result.back() != temp)
                            result.push_back(temp);

                        temp.clear();
                    }
                   
                }

    hash_:            hash_set.insert(nums[j]);
            }
            hash_set.clear();
            

        }

        return result;

        }
};


//new method FINALLY ACCEPTED good performance 45%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;

        
      //  unordered_set<int> hash_set;
        sort(nums.begin(),nums.end());


        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                int front = j+1;
                int back = nums.size()-1;

                while(back > front)
                {
                    int sum = nums[i]+nums[j]+nums[front]+nums[back];
                    if(sum < target)
                        front++;
                    else if(sum > target)
                        back--;

                    else    //equal
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[front]);
                        temp.push_back(nums[back]);
                        result.push_back(temp);

                        //jump the repeat element
                        while(back>front && nums[front] == temp[2])
                            front++;

                        while(back>front && nums[back] == temp[3])
                            back--;

                    }
                }

                while(j<nums.size()-1 && nums[j] == nums[j+1])
                    j++;
            }
            while(i<nums.size()-1 && nums[i] == nums[i+1])
                    i++;
        }

        return result;

    }
};





