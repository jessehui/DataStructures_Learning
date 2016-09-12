//
//  reverse_array.cpp
//  datastucture_test
//
//  Created by Jesse. on 9/11/16.
//  Copyright © 2016 Jesse. All rights reserved.
//

#include <stdio.h>
#include <iostream>

void reverse(int [], int);
void output(int [], int);

int main()
{
    int array[] = {5,4,6,1,7,9,0};
    reverse(array, 7);
    output(array, 7);
    return 0;
    
}



void reverse(int arr[], int length)
{
    int left = 0;
    int right = length - 1;
    int temp;
    while(left<right)   //奇数个元素时, 同时达到同一个值时就会停止.
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

/*
void output(int arr[], int length)
{
   // int i = 0;
    for(int i = 0; i < length ; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

*/

using namespace std;

void output(int arr[], int length)
{
    for(int i = 0; i < length; i++)
        cout << arr[i] << endl;
}





