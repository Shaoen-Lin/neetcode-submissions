class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int dp[101 + 2]; // dp 最後一個也要跑 此外再多加上一個 1

        dp[0]=0;
        dp[1]=0; // 對應到 cost[0]
        dp[2]=0;
        for(int i=3; i<=cost.size()+1 ; ++i)
        {
            dp[i] = min(dp[i-1]+cost[i-2], dp[i-2]+cost[i-3]);
        }

        return dp[cost.size()+1];
    }
};
// dp[i] 定義為走"到"第 i-1 階需要的 min_cost

// dp[n] = min{dp[n-1]+cost[n-1], dp[n-2]+cost[n-2]} 
// dp[0] = 0;
// dp[1] = 0;

// dp[2] = 0;