class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int cnt = 1;
        int n = nums[0];

        if(nums.size() == 1)
            return n;

        for(int i=1 ; i<nums.size() ; ++i)
        {
            if(nums[i] != n)
            {
                cnt = 1;
                n = nums[i];
            }

            while(i<nums.size() && nums[i] == n)
            {
                ++cnt;
                ++i;
            }

            if(cnt > (int)(nums.size()/2))
                return n;
        }
    }
};