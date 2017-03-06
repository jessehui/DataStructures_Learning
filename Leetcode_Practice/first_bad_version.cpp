
//not Accepted 19/21
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int pos = n/2;
        int step = n/2;
        while(true)
        {
        	if(isBadVersion(pos))
        	{
        		step = step/2;
        		pos = pos-step;
        		if(step == 0)
        		{
        			if(isBadVersion(pos-1))
        				return pos-1;
        			else
        				return pos;
        		}
        	}
        	else
        	{
        		step = step/2;
        		pos = pos+step;
        		if(step == 0)
        		{
        			if(!isBadVersion(pos+1))	//
        				return pos+2;
        			else
        				return pos+1;
        		}
        	}
        }
    }
};



//anther try
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int pos = n/2;
        int step = n/2;
        while(true)
        {
        	if(isBadVersion(pos))
        	{
        		step = step/2;
        		pos = pos-step;
        		if(step == 0)
        		{
        			while(isBadVersion(pos))
        			{
        				pos--;
        			}
        			return pos+1;
        		}
        	}
        	else
        	{
        		step = step/2;
        		pos = pos+step;
        		if(step == 0)
        		{
        			while(!isBadVersion(pos))
        			{
        				pos++;
        			}
        			return pos;
        		}
        	}
        }
    }
};



