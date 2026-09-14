class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>visited; // 這次對應保證是 1-to-1 所以後半不是 vector<int>
        // 查找功能 count 只能找前面的值 (前,後) 
        // 這題不能 <index, val> 而是 <val,index> 因為要用 val 來找另一個伴。

        vector<int> ans;

        for(int i=0 ; i<nums.size() ; ++i)
        {
            int need_val = target - nums[i];

            if(!visited.count(need_val))
            {
                visited[nums[i]] = i;
                continue;
            }

            int j = visited[need_val]; // 一維陣列

            ans.push_back(j); // 先放 j 因為 j 較前面
            ans.push_back(i);
        }
        
        return ans;
    }
};
