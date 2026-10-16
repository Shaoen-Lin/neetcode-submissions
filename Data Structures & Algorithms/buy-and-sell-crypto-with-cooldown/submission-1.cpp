class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[5005][2]={0};

        dp[prices.size()][0] = 0; 
        dp[prices.size()][1] = 0; 
        for(int i=prices.size()-1 ; i>=0 ; --i)
        {
            // 後面那天要賣 or 不動，所以今天必定是買
            dp[i][1] = max(dp[i+1][0]-prices[i], dp[i+1][1]);
            // 後面那天要買 or 不動，所以今天必定是賣
            dp[i][0] = max(dp[i+2][1]+prices[i], dp[i+1][0]);
        }

        return dp[0][1]; // 第一天必定沒股票 -> buying
    }
};
// dp[int i][bool buying] "從第 i 天開始"，今天可以買還是可以賣時 => 目前得到最多的錢是多少。
// 因為需要 buttom up 上來，所以必須要從大的開始跑
// 此外，跟 DFS 最大的不一樣在於 DP 不知道今天到底是買還是賣 我們要全部都要討論

// dp[i][n] = max(dp[i-1][0]-prices[i], dp[i-1][1]), if n == 1 (第 i 天 buying == true 可以買)
//          = max(dp[i-2][1]+prices[i], dp[i-1][0]), if n == 1 (第 i 天 buying == true 可以買)

