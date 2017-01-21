//就是不断更新2,3,5的倍数 这样就不用每次都从头开始. 比如8 = 4*2, 4是ugly[3],3这个index
//是不断更新的,表明前边有3个数有2的倍数

class Solution {
public:
    int nthUglyNumber(int n) {
        int i=0, j=0, k=0;
        vector<int> ugly(1,1);
        while(ugly.size() < n)
        {
            ugly.push_back(min(ugly[i]*2, min(ugly[j]*3, ugly[k]*5)));
            if(ugly.back() == ugly[i]*2)
                i++;
            if(ugly.back() == ugly[j]*3)
                j++;
            if(ugly.back() == ugly[k]*5)
                k++;
        }
        return ugly.back();
}
};