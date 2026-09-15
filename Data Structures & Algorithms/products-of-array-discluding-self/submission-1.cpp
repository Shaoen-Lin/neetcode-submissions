class Solution {
public:

    // 這是空間複雜度要湊出 O(1) 的寫法 => 省去 prefix & postfix
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // int prefix[n]; 
        // int postfix[n]; 
        // int output[n]; 
        
        vector<int> output(n);

        int pre=1;
        output[0] = pre; // default
        for(int i=1 ; i<nums.size() ; ++i)
        {
            pre = pre * nums[i-1];
            output[i] = pre;
        }

        int post=1;
        output[nums.size()-1] = post * output[nums.size()-1] ;
        for(int i=nums.size()-2 ; i>=0 ; --i) 
        {
            post *= nums[i+1];
            output[i] = post * output[i];
        }
        // 這裡邏輯比較複雜，i 是要算得那格 
        // output[i] 代表的是前 i-1 格的相乘
        // post 代表 i 後面幾格的乘積

        return output;
    }
};
