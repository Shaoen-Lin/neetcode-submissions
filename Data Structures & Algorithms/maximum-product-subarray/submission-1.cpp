class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_arr[20001];
        int min_arr[20001];

        // Base Case 直接設定第一個數字
        max_arr[0]=nums[0];
        min_arr[0]=nums[0];

        int ans=nums[0]; 
        for(int i=1; i<nums.size() ; ++i)
        {
            // max_arr[i] = max(nums[i]*max_arr[i-1], nums[i]*min_arr[i-1], nums[i]);  
            max_arr[i] = max(nums[i]*max_arr[i-1], nums[i]*min_arr[i-1]);
            max_arr[i] = max(max_arr[i], nums[i]);
            // min_arr[i] = min(nums[i]*min_arr[i-1], nums[i]*max_arr[i-1], nums[i]);
            min_arr[i] = min(nums[i]*min_arr[i-1], nums[i]*max_arr[i-1]);
            min_arr[i] = min(min_arr[i], nums[i]);
            
            ans=max(ans, max_arr[i]);
        }
        return ans;
    }
};

// 定義 max_arr[i] = 看到目前 i 的 Maximum Product Subarray
//     min_arr[i] = 看到目前 i 的 Minimum Product Subarray

// 看 Hackmd

