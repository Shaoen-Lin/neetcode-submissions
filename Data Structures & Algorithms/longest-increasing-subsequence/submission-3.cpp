class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int dp[1001]={0}; // dp[0] => nums[0]

        int ans=1;

        dp[0]=1; // base case
        for(int i=1 ; i<nums.size() ; ++i)
        {
            for(int j=0 ; j<i ; ++j)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1); 
            }
            dp[i] = max(1, dp[i]);

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

// 看 Hackmd