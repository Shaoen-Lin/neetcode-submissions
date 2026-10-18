class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();

        int dp[105][105]={0};

        for(int i=1 ; i<=n ; ++i)
        {
            dp[i][0] = dp[i-1][0]+1;
        }
        for(int j=1 ; j<=m ; ++j)
        {
            dp[0][j] = dp[0][j-1]+1;
        }

        for(int i=1 ; i<=n ; ++i)
        {
            for(int j=1 ; j<=m ; ++j)
            {
                int min_val=1000;
                if(word1[i-1] == word2[j-1])
                {
                    min_val = dp[i-1][j-1];
                }
                
                min_val = min(min_val, dp[i-1][j]+1);   // Insert word1
                min_val = min(min_val, dp[i][j-1]+1);   // Delete word1
                min_val = min(min_val, dp[i-1][j-1]+1); // Replace word1

                dp[i][j] = min_val;
            }
        }
        
        return dp[n][m]; 
    }
};

//     0 1 2 3 4 5 6 7 
//       n e a t c d e e
// 0   0 1 2 3 4 5 6 7 8
// 1 n 1 0
// 2 e 2
// 3 e 3
// 4 t 4
// 5 c 5 
// 6 o 6
// 7 d 7
// 8 e 8

// dp[i][j] = dp[i-1][j-1], if s1[i] == s2[j]
        //  = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
        //           Insert       Delete        Replace

// dp[0][0] = 0
// dp[i][0] = k
// dp[0][j] = k

// 求 dp[n][m] 

