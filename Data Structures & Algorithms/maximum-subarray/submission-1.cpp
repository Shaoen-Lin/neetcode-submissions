class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int dp[100001];

        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1 ; i<nums.size() ; ++i)
        {
            dp[i]=max(dp[i-1]+nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

// subarray 表示字串一定要連續 => 這種 DP 一定不能去記 “跑到目前 i 最大的 sum” 
// 因為不確定你這格會不會被記進去，後面可能不會是連續的。
// 因此要去記的是 "dp[i] 包含自己這格，最大的 sum 是多少"

// 這題可以跟 Maximum Product Subarray 比較

// dp[i] = max(dp[i-1]+nums[i], nums[i])
