#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#include "head.h"
using namespace std;

/*
6
10
9
8
7
6
5

*/

//Not correct very slow
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int num_stu;
    cin>>num_stu;
    
    vector<int> stu_rates;
    for(int i = 0; i<num_stu;i++)
    {
        int temp;
        cin>>temp;
        stu_rates.push_back(temp);
    }
    
    vector<int> candies(num_stu, 1);
    
    for(int i = 0;i<num_stu-1;i++)
    {
        if(stu_rates[i]<stu_rates[i+1])
        {
            candies[i+1] = candies[i]+1;
        }
        else if(stu_rates[i] > stu_rates[i+1])
        {
            int temp = i;
            while(i<num_stu-1 && stu_rates[i] >= stu_rates[i+1])   //find the last place that in descending order
            {
                i++;
            }
            int j;
            for( j = i; j>temp; j --)
            {
                candies[j-1] = candies[j]+1;
     //          cout << "j-1 =" << j-1 << " " << "candies[j] = " << candies[j-1] << endl;
            }
            if(stu_rates[j]>stu_rates[j-1])
                candies[j] = candies[j-1]+1;
            
            
            i--;
            
            
            
        }
//        else    //equal
//        {
//            candies[i+1] = candies[i];
//        }
        
     //   cout << "i =" << i << " " << "candies[i] = " << candies[i] << endl;
    }
    
    int sum = 0;
    for(int i = 0; i< num_stu;i++)
    {
        sum += candies[i];
        cout << "i =" << i << " " << "candies[i] = " << candies[i] << endl;
    }
    
    cout <<  sum << endl;
    
    return 0;
}


//another try
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//#include "head.h"
using namespace std;

/*
6
10
9
8
7
6
5

*/

int get_min(vector<int> minimum, vector<int> stu_rates, int num_stu);
int main()
{
    int num_stu;
    cin>>num_stu;
    
    vector<int> stu_rates;
    for(int i = 0; i<num_stu;i++)
    {
        int temp;
        cin>>temp;
        stu_rates.push_back(temp);
    }
    
    vector<int> minimum(num_stu, 1);
    int result = get_min(minimum, stu_rates, num_stu);
    
//    cout << endl;
    cout << result << endl;
}

int get_min(vector<int> minimum, vector<int> stu_rates, int num_stu)
{
    int con_asc_times = 1;
    int con_des_times = 1;
    for(int i = 0; i<num_stu-1;)
    {
        if(stu_rates[i+1] == stu_rates[i])
        {
            minimum[i+1] = minimum[i]+1;
            i++;
        }
        
        
        while(i<num_stu-1 && stu_rates[i+1]>stu_rates[i])
        {
            if(con_des_times == 1)
                con_asc_times++;
            minimum[i+1] = minimum[i]+con_asc_times;
            con_des_times = 1;
            i++;
        }
        
        
        while(i<num_stu-1 && stu_rates[i+1]<stu_rates[i])
        {
            if(con_asc_times == 1)
                con_des_times++;
            minimum[i+1] = minimum[i]+con_des_times;
            con_asc_times = 1;
            i++;
        }
        
    }
    
 //   print_vec(minimum);
    return minimum.back();
}









