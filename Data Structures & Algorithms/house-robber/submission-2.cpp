class Solution {
public:
    int rob(vector<int>& nums) {
        
        int money[101]={0};
        money[0] = nums[0];

        if(nums.size() == 1)
            return money[0];

        money[1] = max(money[0], 0 + nums[1]);

        for(int i=2; i<nums.size() ; ++i)
        {
            money[i] = max(money[i-1], money[i-2] + nums[i]);
        }

        return money[nums.size()-1];
    }
};

// money 指現在第 n 格最多可以拿到的錢數
// money[n] = max(money[n-1], money[n-2] + nums[n]);
           //  這格拿 or 不拿
        //  = nums[0], if n==0