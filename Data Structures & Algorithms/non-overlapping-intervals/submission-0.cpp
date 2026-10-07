class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int ans=0;
        vector<int> interval = intervals[0];

        for(int i=1 ; i< intervals.size(); ++i)
        {   
            // 有重疊
            if(intervals[i][0] < interval[1])
            {
                ans++;

                // 如果前面比較長要把前面那段踢掉變了
                if(intervals[i][1] < interval[1])
                    interval = intervals[i];
                // else
                //     interval = interval;
                continue;
            }
            else // 沒有重疊
                interval = intervals[i];
        }        

        return ans;
    }
};
