class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();

        int total=0;
        for(int i=0; i<n ; ++i)
        {
            total += nums[i];
        }

        if(total & 1 == 1)
            return false;

        int target = total/2;
        
        // bool dp[55][]={0}; // 0~50 + 1 因為不知道 total 大小所以不能用 array
        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(target+1, false)
        );
        // 但 vector 可以用未知數來訂大小。

        // dp[nums.size()-1][nums[nums.size()-1]] = true;
        dp[n][0] = true;
        for(int i=n-1 ; i>=0 ; --i)
        {
            dp[i][0]=true;

            for(int curr=1 ; curr<=target ; ++curr)
            {
                if(curr>=nums[i]) // 可拿
                {
                    dp[i][curr] = dp[i+1][curr-nums[i]];

                    if(dp[i][curr]==0)
                        dp[i][curr] = dp[i+1][curr];
                }
                else
                    dp[i][curr] = dp[i+1][curr];   
            }
        }
   
        return dp[0][total/2];
    }
};

// 定義 dp[i][remain] 為前 i~n 個東西是否是組出成 remain 的大小
// 求 dp[0][total/2]=?

// dp[i][remain] = dp[i+1][remain-nums[i]], if remain>=nums[i] // 拿 i 
            //   = dp[i+1][remain], // 不拿 i 