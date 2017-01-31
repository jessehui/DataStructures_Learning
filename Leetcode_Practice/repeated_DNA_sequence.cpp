/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example:
 "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences 
(substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> result;
        if(s.size()<10)
            return result;
        unordered_set<string> repeat_DNA;
       // int j = 0;

        for(int i = 0;i<s.size()-9;i++)
        {
        	string sub = s.substr(i,10);
        //	cout << "sub string = " << sub << endl;
        	//no repeat in the result && repeat in the hash set
        	if(repeat_DNA.count(sub)>0 && (find(result.begin(),result.end(),sub) == result.end()) )
        		result.push_back(sub);
        	else
        		repeat_DNA.insert(sub);
        	
        //	j++;
        }
        return result;
    }
};