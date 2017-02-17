/*
Given a non-negative integer represented as a non-empty array of digits,
 plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while(digits[i] == 9)
        	i--;

        //
        if(i == -1)
        {
        	vector<int> result(digits.size()+1, 0);
        	result[0] = 1;
        	return result;
        }
        else
        {
        	digits[i] += 1;
        	for(int j = i+1; j<digits.size(); j++)
        		digits[j] = 0;

        	return digits;
        }	
    }
};

