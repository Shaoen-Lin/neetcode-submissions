class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length();
        int max_cnt = 0;
        string ans;
        

        // odd 檢查
        for(int i=0 ; i<s.length() ; ++i)
        {
            int l = i-1;
            int r = i+1;
            int tmp = 1;
            while(l>=0 && r <= len-1)
            {
                if(s[l] != s[r])
                    break;

                tmp+=2;

                l--;
                r++;
            }

            if(tmp > max_cnt)
            {
                max_cnt = tmp;
                ans = s.substr(l+1, max_cnt);
            }
        }

        // even 檢查(固定找右邊那個跟自己一對)
        for(int i=0 ; i<s.length()-1 ; ++i)
        {
            // 注意寫到 i+1 要小心越界問題
            if(s[i+1] != s[i])
                continue;

            int l = i-1;
            int r = i+2;
            int tmp = 2;
            while(l>=0 && r <= len-1)
            {
                if(s[l] != s[r])
                    break;

                tmp+=2;

                l--;
                r++;
            }

            if(tmp > max_cnt)
            {
                max_cnt = tmp;
                ans = s.substr(l+1, max_cnt);
            }
        }

        return ans;
    }
};

// abbccad