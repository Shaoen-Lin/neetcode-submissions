class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return ans;
    }

    void dfs(int index, vector<int> curr, int total, vector<int>& candidates, int target)
    {
        for(int i=index ; i<candidates.size(); ++i)
        {
            int new_total = total+candidates[i];
            if(new_total == target)
            {
                vector<int> new_curr = curr;
                new_curr.push_back(candidates[i]);
                ans.push_back(new_curr);
                return; // 後面不可能 -> 直接換上一個數字
            }
            else if(new_total > target)
                return; // 因為數字排序過，這輪後面數字不可能->直接換上一個數字
            else
            {
                vector<int> new_curr = curr;
                new_curr.push_back(candidates[i]);
                dfs(i+1, new_curr, new_total, candidates, target);
            }

            while((i<candidates.size()-1) && (candidates[i]==candidates[i+1]))
                ++i;
        }
    }
};

// 這題跟 Combination Sum 不同的點只有一個
// 1. 遞迴的 k 要改成 k+1 -> 因為每個數字只能用一次

// 然後這題可以小加速：
// 一樣的數字可以跳過，因為在前一個數字必定找出所有可能了。
// {1,1,2,3,5} 
// 前一個 1 已經把所有可能看完，後一個 1 可以不用看了 -> 代表要換上一個 -> return


// 