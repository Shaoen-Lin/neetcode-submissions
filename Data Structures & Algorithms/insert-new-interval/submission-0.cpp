class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); ++i)
        {
            // 1. interval 完全在 newInterval 左邊
            if(intervals[i][1] < newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            else if(newInterval[1] < intervals[i][0]) // 2. interval 完全在 newInterval 右邊
            {
                ans.push_back(newInterval);

                // 後面全部都不用檢查了，才不會走到後面的 return
                for(int j = i; j < intervals.size(); ++j)
                    ans.push_back(intervals[j]);

                return ans;
            }
            else // 3. overlap
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        // newInterval 在最後或一路 merge 到最後
        ans.push_back(newInterval);

        return ans;
    }
};

// 1. interval 完全在 newInterval 左邊
// 2. interval 跟 newInterval overlap
// 3. interval 完全在 newInterval 右邊