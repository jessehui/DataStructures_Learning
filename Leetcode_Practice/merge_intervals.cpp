/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/




/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//bug in it
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;

        for(int i = 1; i < intervals.size(); )
        {
            // if(intervals[i-1].start >= intervals[i].start)
            // {
            //     intervals[i-1].start = intervals[i].start;
            //     intervals.erase(intervals.begin()+i);
            //     continue;
            // }
            
            if(intervals[i].start > intervals[i-1].end || intervals[i].end < intervals[i-1].start)
            {
                i++;
                continue;
            }
                
            if(intervals[i-1].end >= intervals[i].start)
            {
                if(intervals[i].start <= intervals[i-1].start)
                {
                    intervals[i-1].start = intervals[i].start;
                }
               
            }
            
            if(intervals[i].end >= intervals[i-1].end)
            {
                intervals[i-1].end = intervals[i].end;
                
            }
            intervals.erase(intervals.begin()+i);
            
            if(intervals[i-1].end < intervals[i].start)
            {
                i++;
            }
            
        
        }
        

        return intervals;
    }
};


//another try
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval itv1, Interval itv2)
{
    return itv1.start<itv2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);

        int min = intervals[0].start;
        int max = intervals[0].end;
        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i].start > max)
            {
                min = intervals[i].start;
                max = intervals[i].end;
                continue;
            }  

            if(intervals[i].start <= max)
            {
                if(intervals[i].end >= max)
                {
                    max = intervals[i].end;
                    intervals[i-1].end = max;
                    intervals.erase(intervals.begin() + i);
                    i --;
                }
                if(intervals[i].end < max)
                {
                    intervals.erase(intervals.begin() + i);
                    i --;
                }
            }
        }
        return intervals;

    }
};













