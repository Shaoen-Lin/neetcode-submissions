class Solution {
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        
        dfs(nums, curr, i+1);

        curr.push_back(nums[i]);
        dfs(nums, curr, i+1);
        curr.pop_back();
        
        return; 
    }

};
