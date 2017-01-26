class Solution {
public:
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
};