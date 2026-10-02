class Solution {
public:
    string longestPalindrome(string s) {

        int len = s.length();
        bool dp[1000][1000] = {0};

        int max_cnt=1;
        int start=0;
        for(int i=0 ; i<len ; ++i) // 長度 == 1
            dp[i][i] = 1;
        
        
        for(int i=0 ; i<len-1 ; ++i)    // 長度 == 2
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1;

                max_cnt=2;
                start=i;
            }
        }

        for(int l=3 ; l<=len; ++l) // 跑長度，從 base case 往上跑
        {
            for(int i=0 ; i+l-1<len ; ++i) // 重要！ i+l-1 是 j 的大小 
            {
                int j=l+i-1; // 注意！ j-i+1 = l
                dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
            
                if(dp[i][j] && max_cnt < l)
                {
                    max_cnt = l;
                    start = i;
                }
            }
        }
        return s.substr(start, max_cnt);
    }
};

// 定義 dp[i][j] = i~j 的 substring 是不是 Palindrome
// dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]), for j-i > 1      => 也就是 長度>2  的時候
// 		    = true , for j == i                                => 也就是 長度=1 的時候 (base case)
// 		    = (s[i] == s[j]), for j=i+1                        => 也就是 長度=2 的時候 (base case)

