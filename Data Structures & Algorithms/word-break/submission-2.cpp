class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[201]={false};
        
        dp[s.length()] = true;  // Edge Case 
        for(int i=s.length()-1 ; i>=0 ; --i)  // 去算 memorization
        {
            for(int j=0 ; j<wordDict.size() ;++j)   // 去 travese Dictionary
            {
                int word_size = wordDict[j].length();
                if( i+word_size<=s.length() && s.substr(i, word_size) == wordDict[j] )
                {
                    dp[i] = dp[i+word_size];
                }

                if(dp[i] == true)
                    break;
            }
        }

        return dp[0];
    }
};

// 去看 Hackmd