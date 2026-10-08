/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:

    // 注意！一定要打 static 不然不能用
    static bool compare(Interval a, Interval b) {
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), compare);

        for(int i=1; i<intervals.size() ; ++i)
        {
            Interval interval = intervals[i-1];
            
            if(interval.end > intervals[i].start)
                return false;
        }
        return true;

    }
};
