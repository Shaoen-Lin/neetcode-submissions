class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int total=0;
        for(int i=0; i<nums.size() ; ++i)
        {
            total += nums[i];
        }

        if(total & 1 == 1)
            return false;
        else 
            return dfs(nums, 0, total/2);
    }

    bool dfs(vector<int>& nums, int index, int goal)
    {
        if(index > nums.size()-1) // 湊不出來
            return false;      

        if(goal == 0)      
            return true;
        
        if(goal >= nums[index]) // 拿 -> 只能在可以拿的時候才能拿
        {
            if(dfs(nums, index+1, goal-nums[index]))
                return true;
        }
        if(dfs(nums, index+1, goal)) // 不拿 -> 能不能拿都要跑
            return true;
        
        return false;
    }
};


// 奇數不可能
// find = Total/2 

// 問題變成能不能用 nums 湊出 find
// 每個數字可選可不選 Brute Force: O(2^n)
