class Solution {
public:

    // 如果我今天用 x 賣掉，而之前最低買入價是 min_p，可以賺多少 
    // 只要把最低價不斷重設就好，設好後面去看有沒有賺的比較多

    int maxProfit(vector<int>& prices) {
        int min_p = prices[0];
        int ans = 0;

        for (int x : prices) {
            min_p = min(min_p, x);
            ans = max(ans, x - min_p);
        }

        return ans;
    }
};