class Solution {
public:

    // 看到時間複雜度是 O(n^2) 在 array 中 => 一定要想到可以去做 sort 
    // 先 sort 完後就可以用類似 two sum 2 去解，只差在第一個數字要先 iteration 去挑 => time:O(n^2)
    // 答案說不能重複，所以在挑第一個數字的時候要避免挑到一樣的 => 避免重複找 + 重複挑答案
    // 但依舊會遇到 例如： nums=[2,2,2,2,2] 挑 6 的情形會挑出一堆 {2,2,2} 即使 a 不一樣但 b,c 會重挑。

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        int duplicate_a;
        int a, b, c; // pointer
        for(a=0 ; a<nums.size()-2 ; ++a)
        {
            if(a > 0 && nums[a] == duplicate_a)
                continue;

            b=a+1;
            c=nums.size()-1;
            while(b < c)
            {
                if(nums[a]+nums[b]+nums[c] == 0)
                {
                    ans.push_back({nums[a], nums[b], nums[c]});

                    int duplicate_b = nums[b];
                    int duplicate_c = nums[c];

                    // 繼續檢查
                    while(nums[++b] == duplicate_b && b < c);
                    while(nums[--c] == duplicate_c && b < c);
                }    
                else if(nums[a]+nums[b]+nums[c] < 0)
                    b++;
                else 
                    c--;
            }

            duplicate_a = nums[a];        
        }
        return ans;
    }
};
