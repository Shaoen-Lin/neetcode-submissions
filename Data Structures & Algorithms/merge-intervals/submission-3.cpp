class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        // 這邊是先用 第一個元素 來排序
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        if(intervals.size() <= 1)
            return intervals;

        vector<int> interval = intervals[0];
        // 跟前一個比
        for(int i=1; i<intervals.size() ; ++i)
        {
            if(interval[0] == intervals[i][0])
            {
                interval[1] = max(interval[1],intervals[i][1]);

                if(i==intervals.size()-1)
                    ans.push_back(interval);
            }
            else if(interval[1] >= intervals[i][0])
            {
                interval[1] = max(interval[1],intervals[i][1]);

                if(i==intervals.size()-1)
                    ans.push_back(interval);
            }
            else
            {
                ans.push_back(interval);
                interval = intervals[i];

                if(i==intervals.size()-1)
                    ans.push_back(intervals[i]);    
            }
                
        }
        return ans;
    }
};
// 排序好後會長以下這些情況：

// Case 1
// [   ]        
// [     ] or   

// Case 2
// [  ]       [    ]
//   [  ] or    [ ]

// Case 3
// [ ]
//    [ ]
