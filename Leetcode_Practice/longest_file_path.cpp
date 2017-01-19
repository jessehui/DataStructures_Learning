class Solution {
public:
    int lengthLongestPath(string input)
{
    istringstream instring(input);  //input to stringstream to process
    unordered_map<int,int> path_len;
    path_len[0] = 0;
    string token;   // to store string get each line
    size_t max_len = 0;
    
    while(getline(instring, token))
    {
        auto pos = token.find_last_of("\t");
        string name = (pos != string::npos)? token.substr(pos+1): token;    //get only the name
        
        size_t depth = token.size() - name.size();  //number of \t
        if(name.find(".") != string::npos)  //it is a file , end of the path
        {
            max_len = max(max_len, path_len[depth] + name.size());
        }
        else
        {
            path_len[depth+1] = path_len[depth] + name.size() + 1;
        }
        
        
    }
    
    return max_len;
}
};