//Find the kth largest element in an unsorted array. 
//Note that it is the kth largest element in the sorted order, 
//not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.


//simple method
bool compare(int a, int b)
{
    return a>b;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int result;
        sort(nums.begin(),nums.end(),compare);
        return result = *(nums.begin() + (k-1));
    }
};


//priority queue (heap)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	priority_queue<int> heap(nums.begin(), nums.end()); 
    	for(int i = k;i >1; i--)
    		heap.pop();
    	return heap.top();

    }
};
