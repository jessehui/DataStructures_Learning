/*The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

*/


//looks right but TLE 124/200
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> result;
        string temp = "";
        vector<int> copy;
        for(int i = 0; i<n; i++)
        {
            copy.push_back(i+1);
        //    cout << copy.back() << endl;
        }
        backtracking(n, k, result,temp, 0,copy);
        return result[k-1];
    }

    void backtracking(int n, int k, vector<string>& result, string temp, int index, vector<int>&copy)
    {
    	if(temp.size() == n)
    	{
    		result.push_back(temp);
    		return;
    	}
    	if(result.size() == k)
    	{
    		return;
    	}

    	for(int i = 0; i< copy.size(); i++)
    	{
    		temp += (copy[i]+'0');
    		copy.erase(copy.begin()+i);
    		backtracking(n,k,result, temp, index+1, copy);
   // 		cout << "after backtracking: " ;
// 			for(auto it = temp.begin(); it!=temp.end(); it++)
// 				cout << *it << " ,";
// 			cout << endl;
			copy.insert(copy.begin()+i, (*(temp.end()-1))-'0');
    		temp.erase(temp.end()-1);
    	}
    }
};


