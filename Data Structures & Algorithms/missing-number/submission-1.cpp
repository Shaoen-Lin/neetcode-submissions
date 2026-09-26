class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int xor_val=0;
        for(int i=0 ; i<nums.size() ; ++i)
        {
           xor_val ^= nums[i];
        }
        // 把所有的 nums 數字做 xor

        for(int i=0 ; i<=nums.size(); ++i)
        {
            xor_val ^= i ;
        }

        return xor_val;
    }
};

