class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int dp[10000]={0};

        for(int i=0 ; i<coins.size() ; ++i) 
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
            for(int j=coins.size()-1 ; j>=0 ;--j)
            {
                if(i>coins[j] && dp[i-coins[j]]!=-1)
                    min_val = min(min_val, dp[i-coins[j]]+1);
            }

            if(min_val == i+1)
                dp[i] = -1;
            else 
                dp[i] = min_val;
        }
        return dp[amount];        
    }
};

// 這題也是去定義 dp[i] 代表錢為 i 元的時候換出來錢幣的最少數量是多少
// 但是我不要去跑 dp[n] = min(dp[n]+dp[0], ...)

// 我的想法應該改為 dp[n] 去看最大的錢幣能不能放進去
// ex. 現在討論的錢幣大小是: coin_val 
// dp[n] = min(dp[n], dp[n-coin_val]+1);