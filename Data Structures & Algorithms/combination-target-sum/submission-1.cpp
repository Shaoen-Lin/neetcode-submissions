class Solution {
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, {}, 0, nums, target);
        return ans;
    }

    // 帶表 nums[i] 後面的都可以跑
    void dfs(int i, vector<int> curr, int total, vector<int>& nums, int target)
    {
        for(int k=i; k<nums.size() ; ++k) // traverse nums
        {
            int new_total = total + nums[k]; 
            if(new_total > target)
                continue;
            else if(new_total == target)
            {
                vector<int> new_curr = curr;
                new_curr.push_back(nums[k]);
                ans.push_back(new_curr);
                continue;
            }
            else
            {
                // curr.push_back(nums[k]);
                vector<int> new_curr = curr;
                new_curr.push_back(nums[k]);

                // dfs(k+1, curr, new_total, nums, target); 
                // 注意因為下一次數字可以重複使用，所以要是 k 不能是 k+1
                dfs(k, new_curr, new_total, nums, target); 
            }
        }
    }
};
