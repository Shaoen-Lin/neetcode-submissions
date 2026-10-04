class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int dp[10000]={0};
        // 因為錢只會需要換 10000 塊的，所以可以忽略 10000 以後的幣值。

        for(int i=0 ; i<coins.size() ; ++i) // 只要看前 amount 的數字的幣值即可，避免看太大浪費空間
        {
            if(coins[i]<=amount)
                dp[coins[i]]=1;
        }

        // recursive
        for(int i=1; i<=amount ; ++i)
        {
            if(dp[i]==1)
                continue;

            int min_val=i+1;
            for(int j=1; j<=i/2 ; ++j)
            {
                if(dp[i-j]!=-1 && dp[j]!=-1)
                    min_val = min(min_val, dp[i-j]+dp[j]);
            }

            if(min_val == i+1)
                dp[i] = -1;
            else 
                dp[i] = min_val;
        }
        return dp[amount];        
    }
};

// 定義 dp[i] 代表錢為 i 元的時候換出來錢幣的最少數量是多少

// coins = [1,5,10], amount = 12

// dp[0] = 0
// dp[1] = 1 
// dp[2] = 2
// dp[3] = 3
// dp[4] = 4
// dp[5] = 1
// dp[6] = max(dp[6]+dp[0], dp[5]+dp[1], ...) = 2
// dp[7] = max(dp[7]+dp[0], dp[6]+dp[1], dp[5]+dp[2], ...) = 3

// dp[n] = max(dp[n]+dp[0], ...)

// TIme: O(10000*10000)