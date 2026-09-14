class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> times(2001, 0); // 因為數字種類最多 2001 個，初始化為 0

        for(int i=0 ; i<nums.size() ; ++i) // 
        {
            times[ nums[i] + 1000 ]++; // 如果拿到 1 就是 1 的位置 ++ 
            // 但最多可能有複數到 -1000 所以平移 1000
            // 1 => 1+1000 = 1001
            // index = 0 其實是 -1000
        }

        // sort(times.begin(), times.end(), greater<int>()); // 大到小排

        vector<pair<int,int>> freq; // 不能直接 sort 因為會把 index 用掉 => pair 解

        for(int i=0 ; i<2001 ; ++i)
        {
            if(times[i] > 0)
            {
                // freq.push_back( {i,times[i]} ); 不能這樣比，因為 sort 會先比 first 在比 second
                // 所以要改成
                freq.push_back( {times[i],i} ); // 不用考慮次數一樣數字不一樣的問題
            }
        }

        sort(freq.begin(), freq.end(), greater<pair<int,int>>());

        vector<int> ans;

        for(int i=0 ; i<k ; ++i)
        {
            ans.push_back(freq[i].second - 1000);
        }

        return ans;
    }
};
