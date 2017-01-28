//
//  test_hash_map.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/26/17.
//  Copyright © 2017 Jesse. All rights reserved.
//

#include "head.h"


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    if(strs.size()<=1)
    {
        result.push_back(strs);
        return result;
    }
    
    int num_vec = 0;
    unordered_map<string, int> group;   //used to store the first type of charaters
    string temp = strs[0];
    sort(temp.begin(),temp.end());
    group.insert(make_pair(temp,num_vec));
    vector<string> new_;
    result.push_back(new_);
    result[0].push_back(strs[0]);
    
    for(int i = 1;i<strs.size();i++)
    {
        string temp = strs[i];
        sort(temp.begin(),temp.end());
        if(group.count(temp))
        {
            result[group[temp]].push_back(strs[i]);
        }
        else
        {
            num_vec++;
            group.insert(make_pair(temp,num_vec));
            result.push_back(new_);
            //    cout << " size = " << result.size() << endl;
            result[group[temp]].push_back(strs[i]); //不能直接push back 还没新建
            
        }
    }
    return result;
    
}


int main()
{
    vector<string> str_groups = {"eat", "tea", "tan", "ate", "nat", "bat"};
    unorderd_set<>
    return 0;
    vector<vector<string>> result = groupAnagrams(str_groups);
    for(int i = 0;i < result.size(); i++)
    {
        for(int j = 0; j< result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
