class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return LCS(s, rev);
    }

    int LCS(string s1, string s2)
    {
        int dp[1001][1001]={0};

        int len1 = s1.size();
        int len2 = s2.size();

        for(int i=1 ; i<=len1 ; ++i)
        {
            for(int j=1 ; j<=len2 ; ++j)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[len1][len2];
    }

};
// LPS 就是 s 和 s的reverse 做 LCS 
