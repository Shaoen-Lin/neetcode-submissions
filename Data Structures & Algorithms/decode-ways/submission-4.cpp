class Solution {
public:
    int numDecodings(string s) {

        if(s[0] == '0')
            return 0;

        int dp[101]={0};
        dp[0] = 1; 
        for(int i=1 ; i<=s.size() ; ++i)
        {
            if(inRange(s[i-1]))
                dp[i] += dp[i-1];

            if(1<i && inRange(s[i-2],s[i-1]))
                dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }

    bool inRange(char n)
    {
        return (n != '0');
    }

    bool inRange(char n1, char n2)
    {
        if(('1'==n1) && ('0'<=n2 && n2<='9'))
            return true;
        else if(('2'==n1) && ('0'<=n2 && n2<='6'))
            return true;
        return false;
    }
};

// 定義 dp[i] 為 s[1~i] 的 Decode Ways

// dp[i] = dp[i-1] , if(inRange(s[i])) // 自己一組
    //   = dp[i-2]+1, if(inRange(cat(s[i-1],s[i]))) // 和前一個一組

// inRange(1<= i <= 26)

// 1 = 1 種 = dp[1]
// 1

// 11 = 2 種 = dp[2]

// 1 1
// 11

// 111 = 3 種 = dp[3]

// 1 1 1
// 11 1 
// 1 11

// 1111 = 5 種 = dp[4]

// dp[n-2] = dp[2] = 2種配上 + 11 = 2
// dp[n-1] = dp[3] = 3種配上 + 1 = 3

