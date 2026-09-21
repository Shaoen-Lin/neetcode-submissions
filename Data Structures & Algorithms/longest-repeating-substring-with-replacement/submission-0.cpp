class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, right=0;
        int freq[26]={0};   // A=0, B=1 ...
        int ans = 0;
        for(right=0 ; right<s.length() ; ++right)
        {
            freq[(int)s[right] - 'A']++;

            int max_freq=0;
            for(int i=0 ; i<26 ; ++i)
                max_freq = max(max_freq, freq[i]);

            if((right-left+1) - max_freq <= k) // 判斷是否 valid
            {
                ans = max(ans, right-left+1);
            }
            else
            {
                freq[(int)s[left] - 'A']--;
                left++;
            }
        }
        return ans;
    }
};

// s="AAABABB"

// 這題已經知道要用 sliding window 去用 O(n) 窮舉
// 但重點是怎麼知道現在現在的 window 是合法的 -> 不合法要調 left
// 所以字數 - freq[max(s[i])] <= k 就可以判斷 valid 
// 不是 valid 代表這個區間已經是最大值了 -> left 必要往前調整。