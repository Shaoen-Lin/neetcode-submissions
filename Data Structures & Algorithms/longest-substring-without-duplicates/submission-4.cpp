class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> window;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); ++right)
        {
            // 判斷 left 不動 right 到底能不能進去 window 了？
            // 如果不行，那代表現在的 left 最多只能到 right - 1 記起來
            // 現在把 left 往右調，調到這個 right 可以進的去
            while(window.count(s[right])) 
            {
                window.erase(s[left]);     // 一路上都可以 erase
                ++left;
            }

            window.insert(s[right]);

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};