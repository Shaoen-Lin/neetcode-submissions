class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,0));

        // initialize 0 元的組成方式
        for(int i=0 ; i<=n ; ++i)
            dp[i][0]=1;

        // amount 是 1~amount
        for(int j=1 ; j<=amount ; ++j) // 一樣是 amount 先定價錢 
        {
            for(int i=n-1 ; i>=0 ; --i) // coin index (只有i= 3 可以、 i= 2、3 可以、i= 1~3 可以)
            {
                if(j >= coins[i])
                    dp[i][j] += dp[i][j-coins[i]];
                
                dp[i][j] += dp[i+1][j];
            }
        }
        return dp[0][amount];
    }
};

// each value in coins is unique. 指的是不能 12 = 1+1+10 = 1+10+1

// dp[m][n] = 價錢為 n 的時候，m ~ coins.size() 的錢是多少？
// dp[i][j] += dp[i][j-coins[i]] （ 拿 coins[j], j )  
        //  += do[i+1][j]        （ 不拿 coins[j])

// Base Case 
// dp[k][0] = 1, k = all i in coins  (也就是都不拿)