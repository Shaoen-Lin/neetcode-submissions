class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n=s1.length();
        int m=s2.length();

        // 這個要補不然會越界存取
        if(n + m != s3.length())
            return false;

        vector<vector<bool>> dp(n+1, vector<bool>(m+1 ,false));

        // Base case:
        dp[n][m] = true;
        for(int j=m-1; j>=0 ; --j)
        {
            if(s3[n+j]==s2[j] && dp[n][j+1]==1)
                dp[n][j]=1;
        }
        for(int i=n-1; i>=0 ; --i)
        {
            if(s3[i+m]==s1[i] && dp[i+1][m]==1)
                dp[i][m]=1;
        }

        // Transition:
        for(int i=n-1; i>=0 ; --i)
        {
            for(int j=m-1; j>=0 ; --j)
            {
                if(s3[i+j]==s1[i] && dp[i+1][j]==1)
                {
                    dp[i][j]=1;
                    continue;
                }

                if(s3[i+j]==s2[j] && dp[i][j+1]==1)
                {
                    dp[i][j]=1;
                    continue;
                }
            }
        }
        
        return dp[0][0];
    }
};

// 定義 `dp[i][j]` 為 true/false 代表 `s1[i ~ n-1]` 和 `s2[j ~ m-1]` 能不能組成 `s3[i+j ~ n-1+m-1]` 的 Interleaving String。

// Base case: dp[n][m] == 1

// dp[m][n] == 1, if s3[i+j] == s1[i] && dp[i+1][j] == 1
        //  == 1, if s3[i+j] == s2[j] && dp[i][j+1] == 1