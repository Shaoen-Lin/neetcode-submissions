class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        int size = s.length();

        cnt += size; // 先把 size=1 的加入 

        // odd
        for(int i=1; i<size ; ++i)
        {
            int l=i-1, r=i+1;
            while(l>=0 && r<=size-1 && s[l]==s[r])
            {
                cnt++;

                l--;
                r++;
            }
        }

        // even
        for(int i=0; i<size ; ++i)
        {
            if(s[i] != s[i+1])
                continue;
            cnt++;

            int l=i-1, r=i+2;
            while(l>=0 && r<=size-1 && s[l]==s[r])
            {
                cnt++;
                
                l--;
                r++;
            }
        }
        return cnt;
    }
};
