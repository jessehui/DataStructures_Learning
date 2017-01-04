//
//  test_container_with_most_water.cpp
//  datastucture_test
//
//  Created by Jesse. on 1/4/17.
//  Copyright © 2017 Jesse. All rights reserved.
////
//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>    //min
using namespace std;

int maxArea2(vector<int>& height) {
    if(height.size() < 2)
        return 0;
    
    int max_area = 0;
    int temp_area = 0;
    vector<int> temp;
    for(int i = 0; i < height.size(); i++)
        for(int j = 1; j < height.size(); j++)
        {
            if(i>j)
                continue;
            
            cout << "区域最小的高度为 : " << *min_element(height.begin()+i, height.begin()+j+1) << "  ";
            temp_area = (j-i) *  (*min_element(height.begin()+i,height.begin()+j+1));
            cout << "temp area = " << temp_area << endl;
            if(temp_area > max_area)
                max_area = temp_area;
        }
    
    return max_area;
    
    
    
    
}

int maxArea3(vector<int>& height) {
    if(height.size() < 2)
        return 0;
    
    int max_area = 0;
    int temp_area = 0;
    
    for(int i = 0; i < height.size(); i++)
        for(int j = 1; j < height.size(); j++)
        {
            if(i>=j)
                continue;
            
            temp_area = (j-i) *  min(height[i],height[j]);
            cout << "temp area = " << temp_area << endl;
            if(temp_area > max_area)
                max_area = temp_area;
        }
    
    return max_area;
    
    
    
    
}

int maxArea(vector<int> &height)
{
    int l = 0;
    int r = height.size()-1;
    if(r<1)
        return 0;
    
    int temp_area, max_area = 0;
    
    while(r-l >= 1)
    {
        temp_area = min(height[r],height[l]) * (r-l);
        if(temp_area > max_area)
            max_area = temp_area;
        
        //move the index
        if(height[r] > height[l])
            l++;
        else
            r--;
        
    }
    return max_area;
}


int main()
{
    vector<int> height = {1,1};
    int max_area = maxArea(height);
    cout << " max_area = " << max_area << endl;
    return 0;
}
