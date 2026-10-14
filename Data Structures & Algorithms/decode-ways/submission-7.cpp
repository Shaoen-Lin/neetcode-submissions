class Solution {
public:
    int numDecodings(string s) {
        
        int dp[101]={0};

        if(inRange(s[s.length()-1]))
            dp[s.length()-1]=1;
        
        if(s.length() == 1)
            return dp[0];

        if(inRange(s[s.length()-2], s[s.length()-1]))
            dp[s.length()-2] = dp[s.length()-1] + 1;
        else if(inRange(s[s.length()-2]))
            dp[s.length()-2] = 1;
        
        for(int i=s.length()-3 ; i>=0 ; --i)
        {   
            // if(!inRange(s[i], s[i+1]) && !inRange(s[i]))
            //     return 0;

            if(inRange(s[i]))
                dp[i] += dp[i+1];
            
            if(inRange(s[i], s[i+1]))
                dp[i] += dp[i+2];
        }
        return dp[0];
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
// 定義 dp[i] 為 i~n 的 Decode Ways

// dp[n] = 1 , if inRange(n)
// dp[n-1] = + dp[n-1 + 2], if inRange(dp[n-1], dp[n])
        // = + dp[n-1 + 1], if inRange(n+1)
        // = 0 , if !inRange(n) && !inRange(n-1)
