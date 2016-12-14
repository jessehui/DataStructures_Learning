bool compare(int a, int b)
{
	return a<b;
}



class Solution {
public:

	double getMedian(vector<int>& nums)
	{
		double median;
		if(nums.size() == 0)
		    return median = 0;
		
		if(nums.size()%2 == 1)//奇数个
		{
			median = (double)nums[nums.size()/2];
		}
		else //偶数个
			median = ((double)nums[nums.size()/2 - 1] + (double)nums[nums.size()/2]) / 2;

		return median;
	}
	
	


//accepted 13%左右 但是理论上这个不是O(log(m+n)) 不知道为什么会通过
//注释部分的代码利用了类似二分法 但是不能准确控制边界数 总是差个一点半点的 不知道怎么解决	
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
        double median_1, median_2;
	    median_1 = getMedian(nums1);
        median_2 = getMedian(nums2);

	    if(1)
        {
        	vector<int> temp;
        	temp.insert(temp.begin(), nums1.begin(),nums1.end());
        	temp.insert(temp.begin(), nums2.begin(),nums2.end());
        	sort(temp.begin(),temp.end(),compare);
        // 	cout << "temp = ";
        // 	for(vector<int>::iterator it = temp.begin(); it!=temp.end(); ++it)
        // 	    cout << *it << " ";
        // 	cout << endl;
        	return getMedian(temp);

        }

    //     vector<int>sub1_right (nums1.end() - nums1.size()/2 - 1, nums1.end());
    //     vector<int>sub1_left (nums1.begin(), nums1.begin() + nums1.size()/2 + 1);   //后边的参数相当于end iterator所以要大一个
    //     vector<int>sub2_right (nums2.end() - nums2.size()/2 - 1, nums2.end());
    //     vector<int>sub2_left (nums2.begin(), nums2.begin() + nums2.size()/2 + 1);


    //     if(median_1 < median_2)	//median_1左边的1的数组都不用要了 同理median_2右边的2数组也不用要了
    //     {
    //     	return findMedianSortedArrays(sub1_right,sub2_left);        	
    //     }
    //     if(median_1 > median_2)
    //     {
    //     	return findMedianSortedArrays(sub1_left,sub2_right); 
    //     }
    //     else	//相等的话
    //     	return median_1;

    // }






        int find(vector<int>& nums1, vector<int>& nums2)
        {
        	median_1 = getMedian(nums1);
        	median_2 = getMedian(nums2);

        	vector<int>sub1_right (nums1.end() - nums1.size()/2, nums1.end());
         	vector<int>sub1_left (nums1.begin(), nums1.begin() + nums1.size()/2);   //后边的参数相当于end iterator所以要大一个
        	vector<int>sub2_right (nums2.end() - nums2.size()/2, nums2.end());
    	    vector<int>sub2_left (nums2.begin(), nums2.begin() + nums2.size()/2);

        	if(median_1 < median_2)
        	{
        		find()

        	}


        }


        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
        double median_1, median_2;
	    median_1 = getMedian(nums1);
        median_2 = getMedian(nums2);
        size1 = nums1.size();
        size2 = nums2.size();

        if( (size1+size2)&2 == 1 )
        {
        	//找最中间的元素即可
        	return find(nums1,nums2);
        }

    }

};




