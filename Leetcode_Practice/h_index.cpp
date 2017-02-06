/*
Given an array of citations (each citation is a non-negative integer) 
of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index 
h if h of his/her N papers have at least h citations each, and the other N − h 
papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher 
has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations 
respectively. Since the researcher has 3 papers with at least 3 citations each
 and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.


一个人在其所有学术文章中有N篇论文分别被引用了至少N次，他的H指数就是N。
*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
    // 	if(citations.size() == 1 && citations[0] == 0)
    // 		return 0;
    // 	else return 1;
    
        if(citations.size()<1)
            return 0;
    	if(citations.size() == 1)
    	{
    	    switch(citations[0])
    	    {
    	        case 0:return 0; 
    	        default:return 1;
    	    }
    	}

        int h;
        sort(citations.begin(),citations.end());
        vector<int> temp;
      //  temp.push_back(citations.back());
        //int less;	//number less than h citations
        int size = citations.size();
        if(size == 2)
        {
            if(citations.back() >= size-1)
            {
                if(citations.front() > size-1)
                    return 2;
                else
                    return 1;
            }
            else return 0;
        }

        for(int i = citations.size()-1 ;i >= 0; i--)
        {
        	h = citations[i];
        	if(temp.size() < h)
        	    temp.push_back(h);
        	if(temp.size() >= h)
        		return temp.size();
        }
        
        return temp.size();

    //    return -1;

    }
};


