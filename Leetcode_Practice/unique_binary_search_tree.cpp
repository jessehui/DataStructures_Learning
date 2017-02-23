/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


*/



//Ideas:
/*
The problem is to calculate the number of unique BST. 
To do so, we need to define two functions:

G(n): the number of unique BST for a sequence of length n.

F(i, n), 1 <= i <= n: the number of unique BST, where the number i 
is the root of BST, and the sequence ranges from 1 to n.

Thus:
G(n) = F(1, n) + F(2, n) + ... + F(n, n).

Given a sequence 1…n, we pick a number i out of the sequence as the 
root, then the number of unique BST with the specified root F(i), 
is the cartesian product of the number of BST for its left and 
right subtrees. For example, F(3, 7): the number of unique BST 
tree with number 3 as its root. To construct an unique BST out of 
the entire sequence [1, 2, 3, 4, 5, 6, 7] with 3 as the root, which 
is to say, we need to construct an unique BST out of its left 
subsequence [1, 2] and another BST out of the right 
subsequence [4, 5, 6, 7], and then combine them together 
(i.e. cartesian product). The tricky part is that we could 
consider the number of unique BST out of sequence [1,2] as G(2), 
and the number of of unique BST out of sequence [4, 5, 6, 7] as G(4). 
Therefore, F(3,7) = G(2) * G(4).

i.e.

F(i, n) = G(i-1) * G(n-i)	1 <= i <= n 


Combining the above two formulas, 
we obtain the recursive formula for G(n). i.e.

G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0) 
*/


//very slow. just recursive no DP
class Solution {
public:
	//int result = 0;
    int numTrees(int n) {
      if(n == 1)  
      	return 1; 	//result += 1;
      if(n == 0)	
      	return 1; 	//result += 1;

      else
      {
        int temp = 0;
      	for(int i = 0; i<n; i++)
      	{
      		temp += numTrees(i)*numTrees(n-i-1);
      		cout << "i = " << i << "  temp = " << temp << endl;
      	}
      	
      	cout << "before return temp = " << temp << endl;
      	return temp;
        
      }
   //   return result;
    }
    
};


//another try DP

class Solution {
public:
    int numTrees(int n) {
    	vector<int> uni_BST(n+1,0);	//number of unique BST for each case with n nodes
    	uni_BST[0] = 1;
    	uni_BST[1] = 1;

    	for(int i = 2; i<= n; i++)
    	{
    		for(int j = 0; j < i; j++)
    		{
    			uni_BST[i] += uni_BST[j]*uni_BST[i-1-j];
    		}
   // 	    cout << "uni_BST[" << i << "] = " << uni_BST[i] << endl;
    	}
    	

    	return uni_BST[n];


    }
};





//18

// Your answer

// 477638700

// 2147483647 

