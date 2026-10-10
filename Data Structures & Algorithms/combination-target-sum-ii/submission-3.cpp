class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(0, curr, 0, candidates, target);
        return ans;
    }

    void dfs(int index, vector<int>& curr, int total, vector<int>& candidates, int target)
    {
        for(int i=index ; i<candidates.size(); ++i)
        {
            int new_total = total+candidates[i];
            if(new_total == target)
            {
                // vector<int> new_curr = curr;
                curr.push_back(candidates[i]);
                ans.push_back(curr);
                curr.pop_back();
                return; // 後面不可能 -> 直接換上一個數字
            }
            else if(new_total > target)
                return; // 因為數字排序過，這輪後面數字不可能->直接換上一個數字
            else
            {
                // vector<int> new_curr = curr;
                curr.push_back(candidates[i]);
                dfs(i+1, curr, new_total, candidates, target);
                curr.pop_back();
            }

            while((i<candidates.size()-1) && (candidates[i]==candidates[i+1]))
                ++i;
            // 重點：i 是這個 for 迴圈的參數
            // 所以即使 return 後也不會影響上個 function 的 i
        }
    }
};