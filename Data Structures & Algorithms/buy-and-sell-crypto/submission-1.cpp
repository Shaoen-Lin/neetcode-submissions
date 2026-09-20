class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_p=101, max_p=-1;
        int ans=0;
        for(int x: prices)
        {
            if(min_p > x)  // 先看最小的換不換
            {   
                min_p = x;
                max_p = -1; // max_price 要重新計算
            }
            else if(max_p < x) 
            {
                max_p = x;
            }

            ans = max(ans, max_p - min_p);
        }
        return ans;
    }
};
