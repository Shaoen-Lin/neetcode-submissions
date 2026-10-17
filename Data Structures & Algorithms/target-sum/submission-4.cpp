class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();

        int total=0;
        for(int i=0 ; i<n ; ++i)
            total += nums[i];

        if(target < -total || target > total)
            return 0;
        
        vector<vector<int>> dp (n+1, vector<int>(total*2+1, 0)); // -total~0~total

        int shift = total;
        dp[n][0+shift]=1;
        for(int i=n-1 ; i>=0 ; --i)
        {
            // 負數不能當 index -> 因此右移成 -total ~ total -> 0 ~ 2*total  
            for(int sum=0 ; sum<=2*total ; ++sum)
            {
                if(0 <= sum - nums[i])
                    dp[i][sum] += dp[i+1][sum-nums[i]]; // j-nums[i] 代表可以透過 +nums[i] 組出 j 的人
                if(sum + nums[i] <= 2 * total)
                    dp[i][sum] += dp[i+1][sum+nums[i]];
            }
        }

        return dp[0][target+shift];
    }
};

// dp[i][sum], i 是 index, sum 是 +- sum of the nums 代表算 i~n 項的組出 sum 的可能 premutation 是多少？

// dp[i][j] += dp[i+1][j-nums[i]], for all j in target
//          += dp[i+1][j+nums[i]], for all j in target

// Base Case
// dp[n][0] == 1
// dp[i][j] 初始 == 0