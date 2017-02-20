/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors 
are in the given prime list primes of size k. For example,
 [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence 
 of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

*/

// class Solution {
// public:
//     int nthSuperUglyNumber(int n, vector<int>& primes) {
//         priority_queue<int> result;
//         result.push_back(1);
//         for(auto it = primes.begin(); it!= primes.end(); it++)
//         {
//         	result.push_back(*it);
//         }

//         //already get the initial number
//         for(int i = 1; i < n; i++)
//         {
//         	result.push_back(result[i]*result[j]);
//         }




//     }
// };

//it works but 80/83 TLE
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	
    	vector<int> result(1,1);
    	while(result.size() < n)
	    {
            priority_queue<int, vector<int>, greater<int>> temp;    //min heap
	    	for(int i = 0; i< primes.size(); i++)
	    	{
	    		for(auto it = result.begin(); it!=result.end(); it++)
	    		{
//	    		    cout << "push :" << (*it) * primes[i] << " ";
	    			temp.push((*it)*primes[i]);
	    		}
	    	}
	   // 	cout << "temp top = " << temp.top() << endl;
	   // 	cout << "result back = " << result.back() << endl;
	    	while(temp.top() <= result.back())
	    	    temp.pop();
	    	result.push_back(temp.top());
	    }
	    return result.back();

    }
};



//Accepted
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
  		map<int, int> index; 	//index[2] - 0, index[7] - 0 ...etc
  		for(int i = 0; i<primes.size(); i++)
  		{
  			index[primes[i]] = 0;
  		}

  		vector<int> result(1,1);	//init 1 
  		while(result.size()<n)
  		{
  			priority_queue<int, vector<int>, greater<int>> temp;
  			for(int i = 0;i<primes.size();i++)
  			{
  				temp.push(primes[i] * result[index[primes[i]]]);
  			}

  			result.push_back(temp.top());
  			
  			for(int i = 0;i<primes.size();i++)
  			{
  				if(temp.top()%primes[i]==0)
  					index[primes[i]]++;
  			}
  		}

  		return result.back();
    }
};

