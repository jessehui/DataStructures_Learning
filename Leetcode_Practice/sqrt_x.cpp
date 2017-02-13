// Implement int sqrt(int x).

// Compute and return the square root of x.

//newton's method
class Solution {
public:
    int mySqrt(int x) {
        double delta = 0.01;
        long ans = x;
        while(abs(pow(ans,2)) - x > delta)
        {
            ans = (ans+x/ans)/2;    // if x/ans == ans then we get the result. so it is approaching the result by using average value
        }
        
        return int(ans);
    }
};



//binary search
class Solution {
public:
    int mySqrt(int x) {
        long left = 1, right = x;
        long middle = (right+left)/2;
        while(1)
        {
            if((middle+1)*(middle+1) > x && middle*middle < x)
                return middle;
            
            if(middle*middle > x)
            {
                right = middle-1;
            } 
            else if(middle*middle < x)
                    left = middle+1;
            else return middle;
            
            
            
            middle = (left+right)/2;
            // cout << "left = " << left << " ";
            // cout << "middle = " << middle << " ";
            // cout << "right = " << right << endl;
        }
    }
};