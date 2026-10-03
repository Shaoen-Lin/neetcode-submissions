class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int dp[1001][1001]={0};        // 因為最外圍那圈要是 0，改成 test1[1~i]
        int size1 = text1.length();
        int size2 = text2.length();

        // base case
        // for(int i=0; i<=size1; ++i)
        // {
        //     for(int j=0; j<=size2; ++j)
        //     {
        //         if(i==0 || j==0)
        //             dp[i][j]=0;
        //     }
        // }

        // recursive
        for(int i=1; i<=size1; ++i)
        {
            for(int j=1; j<=size2; ++j)
            {
                if(text1[i-1]!=text2[j-1])
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                else 
                    dp[i][j] = dp[i-1][j-1]+1;
            }
        }

        return dp[size1][size2];
    }
};

// 1. dp[i][j] 代表 test1[0~i-1] 字串 和 test1[0~j-1] 字串的 LCS

// 2. dp[i][j] = max(dp[i-1][j], dp[i][j-1]), if test1[i] != test2[j]
            // = dp[i-1][j-1]+1, if test1[i] == test2[j]
            // = 0. for i=-1 || j=-1 (因為 dp[0][0] 代表第 0 和第 0 比較)

// 3. 因為需要 上、左、左上格子 且
// x x x x x x x 
// x * * * * * ->
// x
// x
// x

// 所以是往橫的走，正常跑 row major 

// 4. return dp[size1][size2]