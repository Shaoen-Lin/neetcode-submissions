class Solution {
private:
    vector<vector<int>> ans;    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr = {};
        vector<bool> used(7, false);
        dfs(nums, curr, used);
        return ans;
    }

    // 其實 used 用 hash set 也可以，但重點不太於這個數值有沒有被用過，是這個位置得數字有沒有被用過
    void dfs(vector<int>& nums, vector<int>& curr, vector<bool>& used)
    {
        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for(int i=0 ; i<nums.size() ; ++i)
        {
            if(used[i])
                continue;
            
            used[i] = true;
            
            curr.push_back(nums[i]);
            dfs(nums, curr, used);
            curr.pop_back();

            used[i] = false;
        }
    }
};

// used 版本 
