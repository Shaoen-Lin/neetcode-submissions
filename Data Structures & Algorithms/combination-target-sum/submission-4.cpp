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
                // vector<int> new_curr = curr;
                curr.push_back(nums[k]);
                ans.push_back(curr);
                curr.pop_back();
                continue; // -> 代表是換這層數字
            }
            else
            {
                // vector<int> new_curr = curr;
                curr.push_back(nums[k]);
                dfs(k, curr, new_total, nums, target); 
                curr.pop_back();
            }
        }
    }
};

// 這題 curr 改成 pass by reference 
