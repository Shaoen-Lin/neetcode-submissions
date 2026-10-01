class Solution {
public:
    int climbStairs(int n) {
        int cnt[46] = {0};

        cnt[0] = 1;
        cnt[1] = 1;
        for(int i=2; i<=n ; ++i)
        {
            cnt[i] = cnt[i-1] + cnt[i-2];
        }

        return cnt[n];
    }
};
// climb[n] = climb[m-1] + climb[m-2]