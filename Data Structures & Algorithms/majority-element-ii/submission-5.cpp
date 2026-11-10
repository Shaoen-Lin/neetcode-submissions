class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ans;

        int cnt = 1;
        int n = nums[0];
        
        if(nums.size() < 3)
            return nums;

        for(int i=1 ; i<nums.size() ; ++i)
        {
            if(nums[i] != n)
            {
                cnt = 1;
                n = nums[i];
            }
            else 
            {
                // 把這個數字全部跑完 才不會有重複塞進 array 的問題
                while(i<nums.size() && nums[i] == n)
                {
                    ++cnt;
                    ++i;
                }

                if(cnt > (int)(nums.size()/3))
                    ans.push_back(n);

                if(i<nums.size())
                {
                    cnt = 1;
                    n = nums[i];
                }
            }
        }

        return ans;
    }
};