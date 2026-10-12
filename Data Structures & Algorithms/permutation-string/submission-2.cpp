class Solution {

// 因為題目只有 lowercase English letters，所以根本不用 unordered_map 用 int count[26] = {0};

public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length())
            return false;

        int count1[26] = {0};
        int count2[26] = {0};

        int window = s1.length(); // window 長度是 s1 的長度

        // s1 的 frequency
        for(char c : s1)
            count1[c - 'a']++;

        // s2 第一個 window
        for(int i = 0; i < window; ++i)
            count2[s2[i] - 'a']++;

        // 第一個 window
        if(equal(count1, count2))
            return true;

        // 開始 sliding
        for(int right = window; right < s2.length(); ++right)
        {
            // 新字元進來
            count2[s2[right] - 'a']++;

            // 最左邊字元出去
            int left = right - window;
            count2[s2[left] - 'a']--;

            if(equal(count1, count2))
                return true;
        }

        return false;
    }

private:
    bool equal(int a[], int b[])
    {
        for(int i = 0; i < 26; ++i)
        {
            if(a[i] != b[i])
                return false;
        }

        return true;
    }
};

// 時間複雜度: O(n), n 為 s2 的長度