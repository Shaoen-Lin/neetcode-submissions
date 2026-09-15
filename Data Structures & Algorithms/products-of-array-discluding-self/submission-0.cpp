class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        int prefix[n]; 
        int postfix[n]; 
        // int output[n]; 
        vector<int> output(n);

        prefix[0] = nums[0];
        for(int i=1 ; i<nums.size() ; ++i)
        {
            prefix[i] = prefix[i-1] * nums[i];
        }

        postfix[nums.size() - 1] = nums[nums.size() - 1];
        for(int i=nums.size()-2 ; i>=0 ; --i)
        {
            postfix[i] = postfix[i+1] * nums[i];
        }

        output[0] = 1 * postfix[1];
        output[nums.size() - 1] = prefix[nums.size() - 2] * 1;
        for(int i=1 ; i<nums.size()-1 ; ++i)
        {
            output[i] = prefix[i-1] * postfix[i+1];
        }

        return output;
    }
};
