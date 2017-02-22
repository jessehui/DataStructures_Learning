/*
 * Complete the function below.
 */
int maxDifference(vector < int > a) {
    if(a.size()<=1)
        return -1;
    int result = -1;
    int mini = a[0];
    //int max = a[1];
    for(int i = 1; i< a.size(); i++)
    {
    	if(a[i]-mini > result)
        {
            result = a[i]-mini;
        }
        if(a[i]<mini)
        {
            mini = a[i];
        }    
    }
  //  cout << "result = " << result << endl;
    return result;

}

//I can't see test cases... I don't know which corner case I am missing.
