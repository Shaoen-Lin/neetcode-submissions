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
    int minMeetingRooms(vector<Interval>& intervals) {
        
        vector<int> start;
        vector<int> end;

        for(int i=0 ; i<intervals.size() ; ++i)
        {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int cnt=0;
        int ans=0;

        int i=0, j=0;
        while(i<intervals.size() && j<intervals.size())
        {
            if(start[i] < end[j])
            {
                cnt++;
                i++;
            }
            else if(start[i] >= end[j]) // 題目說相撞會先釋放
            {
                cnt--;
                j++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
// 這題核心想法就是 把 start time 和 end time 分開並且拿去排序好 (可以分別得到使用時間、釋放時間陣列)
// 去看 => 下一場會議開始的時間，比目前最早會結束的會議還早。
// 如果沒有就代表原本會議室都在用之外，還要多新增一間會議室
// 如果沒有，代表目前有一場場結束了，會議室可以釋放一間。
