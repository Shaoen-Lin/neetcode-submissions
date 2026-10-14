class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int dp[100+2]; // dp 多加上 2 因為一個是 top，此外再多加上一個 1

        dp[0]=0; // 對應到 cost[0]
        dp[1]=0; 
        for(int i=2; i<=cost.size() ; ++i) // dp 跑 1~cost.size()
        {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }

        return dp[cost.size()];
    }
};

// 這題題目沒寫好 是要走到 top！並不是走到 cost.size()-1

// dp[0] = 到 cost[0] 這一階
// dp[1] = 到 cost[1] 這一階
// dp[2] = 到 cost[2] 這一階
// ...
// dp[n-1] = 到樓梯前一階 = 到 cost[cost.size()-1] 這一階
// dp[n] = 到樓梯頂端 top = 到 cost[cost.size()] 這一階

// dp[i] 定義為走"到"第 i 階需要的 min_cost (只是到達這一階，還沒有踩它、所以還沒付這一階的 cost)

// dp[n] = min{dp[n-1]+cost[n-1], dp[n-2]+cost[n-2]} 
// dp[1] = 0; 
// dp[2] = 0;

// cost = [1,2,3,top]
// dp = [0,0,1,2]
