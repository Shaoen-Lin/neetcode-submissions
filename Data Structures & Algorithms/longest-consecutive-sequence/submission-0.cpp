class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> visited(nums.begin(), nums.end()); // 這樣寫法就是放進所以 nums[i]

        // 重要的想法
        // 1. 看到 s.count(s[i-1]) != false 在來取得"連續的長段" => 而不是慢慢去數 1 1 1 1
        
        int max_cnt = 0;
        for(int num : visited)
        {
            if(visited.count(num - 1) == 0) // 檢查目前數字是不是開頭，開頭再進來算長度才有機會
            {
                int cnt = 0;
                while(visited.count(num) == 1)
                {
                    cnt++;
                    num++;
                }
                max_cnt = max(cnt, max_cnt);
            }
        }
        return max_cnt;
    }
};
