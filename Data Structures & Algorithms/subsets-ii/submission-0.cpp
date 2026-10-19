class Solution {
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<int> curr = {};
        dfs(nums, curr, 0);

        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& curr, int i)
    {
        if(i == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        // 放進去 nums[i]
        curr.push_back(nums[i]);
        dfs(nums, curr, i+1);
        curr.pop_back();

        // 不要放進去 nums[i] -> 代表要去檢查下一個是不是也等於 nums[i]
        int tmp = nums[i];
        while(i+1 < nums.size() && nums[i+1] == tmp)
        {
            ++i;
        }
        dfs(nums, curr, i+1);

        return;
    }
};

// 只有放進去 nums[i] 的分支才可以繼續放 nums[i] 的數值！