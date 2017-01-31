/*Count the number of prime numbers less than a non-negative number, n.


we can mark off multiples of 5 starting at 5 × 5 = 25, 
because 5 × 2 = 10 was already marked off by multiple of 2,
 similarly 5 × 3 = 15 was already marked off by multiple of 3. 
 Therefore, if the current number is p, we can always mark off multiples of p 
 starting at p2, then in increments of p: p2 + p, p2 + 2p, ...
*/


class Solution {
public:
    int countPrimes(int n) {
    int count = 0;
    if(n <= 1)
        return count;
    vector<bool> number(n,true);
    
    for(int i = 2; i*i <= n; i++)   //just need to check  number<sqrt(n)
    {
        if(!number[i])
            continue;
        for(int j = i*i; j < n; j+=i)	//reason listed above
        {
            number[j] = false;
   //         cout << "not prime numbers: " << j << " ";
        }
        cout << endl;
    }
    
    
    for(int i = 2; i<n; i++ )
    {
        if(number[i] == true)
        {
            count ++;
    //        cout << " prime numbers " << i << " ";
        }
    }
  //  cout << endl;
    return count;
    
}
};