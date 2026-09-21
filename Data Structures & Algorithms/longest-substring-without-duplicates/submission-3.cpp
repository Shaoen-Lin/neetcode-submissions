class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;

        int left=0, right=0;
        int ans=0, cnt=0;

        for(right=0 ; right<s.size() ; ++right)
        {
            if(!set.count(s[right]))
            {
                set.insert(s[right]);
                ++cnt;
                ans = max(ans, cnt);
            }
            else 
            {
                while(left<right)   // 檢查 left 應該要縮到哪一格
                {
                    if(s[left] == s[right])
                    {
                        ++left; // left 前進一格，但因為加入一樣的字所以這輪 cnt 不用變動
                        break; // 一樣就不要 erase 了，怕會 erase 到同個字
                    }   
                    else 
                    {
                        set.erase(s[left]);
                        ++left;
                        --cnt;
                    }
                }
            }
        }
        return ans;
    }
};
