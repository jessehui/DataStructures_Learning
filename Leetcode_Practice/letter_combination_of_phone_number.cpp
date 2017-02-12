/*

Given a digit string, return all possible letter combinations
 that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/


// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         if(digits.size()<1)
//             return {};

//         for(int i = 0;i<digits.size();i++)
//         {
//             switch(digits[i])
//             {
//                 case '2': 
//                 {

//                 }
//             }

//         }
//     }
// };

class Solution {
public:
    vector<string> dic = {{"0"},{"1"},{"abc"},{"def"},
    {"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};

   // vector<string> result;

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        for(int i = 0;i<digits.size();i++)      //for every digits "3", "4" ..
        {
            int num = digits[i] - '0';
            vector<string> pre = result;
            if(result.size() == 0)
                pre = {""};
            result.clear();
            for(int j = 0; j<dic[num].size(); j++)  //for every corresponding char "d" in "def"
            {
                char temp = dic[num][j];//|| (pre.size() == 0 && k < 1)
        //        cout << "temp = " << temp << " ";
                for(int k = 0; k < pre.size()  ; k++) //for every set of result in last loop 
                {
                    string new_string = pre[k]+temp;
             //       cout << "new string = " << new_string << " " << endl;;
                    result.push_back(new_string);
                }
            }
        }
   //     sort(result.begin(),result.end());
        return result;



    }
};


