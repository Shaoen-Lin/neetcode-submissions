class Solution {
private:
    vector<vector<int>> ans;    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr = {};
        dfs(nums, curr);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& curr)
    {

        if(nums.empty())
        {
            ans.push_back(curr);
            return;
        }

        // if(curr.size() == nums.size())
        // {
        //     ans.push_back(curr);
        //     return;
        // }

        for(int i=0 ; i<nums.size() ; ++i)
        {
            int tmp = nums[i];
            nums.erase(nums.begin() + i);

            curr.push_back(tmp);
            dfs(nums, curr);
            curr.pop_back();

            nums.insert(nums.begin() + i, tmp);
        }
    }
};

// 這種寫法會有兩個問題
// 1. nums.size() 會一直被拿，導致不能判斷 curr.size() == nums.size()
// 2. nums 裡面得數字需要 拿掉 跟 插入 一樣的位置，所以要用 insert 和 erase

// 通常都用 vector<bool> used[] 解決問題