class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[1001]={0};

        dp[nums.size()-1]=1;
        for(int i=nums.size()-2 ; i>=0 ; --i)
        {
            // if(nums[i]+i==nums.size()-1 || dp[nums[i]+i]==1)
            //     dp[i]=1;

            for(int j=1 ; j<=nums[i] ; ++j)
            {
                if(dp[j+i]==1)
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};

// define dp[i] = 第 i 格能不能走到最後一格

// dp[n-1]=true
// dp[n-2]=true, if nums[n-2] == 1
// dp[n-3]=true, if nums[n-3] == 1 && dp[n-2] == 1 || nums[n-3] == 2
// dp[n-4]=true, if nums[n-4] == 1 and dp[n-2] == 1 || nums[n-4] == 2 and dp[n-2] == 1 || nums[n-4] == 3