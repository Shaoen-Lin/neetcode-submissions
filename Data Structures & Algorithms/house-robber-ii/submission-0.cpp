class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        // 只有一間房時，直接偷這間
        if(n == 1)
            return nums[0];

        // Case A：必定不考慮最後一間
        // 範圍 [0 ... n-2]
        int caseA = rob1(nums, 0, n - 2);

        // Case B：必定不考慮第一間
        // 範圍 [1 ... n-1]
        int caseB = rob1(nums, 1, n - 1);

        return max(caseA, caseB);
    }

    int rob1(vector<int> nums, int start, int end)
    {
        int money[101]={0};

        // 只有一個元素
        if(end == start)
            return nums[start];

        money[start] = nums[start];
        money[start+1] = max(nums[start+1], 0+money[start]);
        for(int i=start+2 ; i<=end ; ++i)
        {
            money[i] = max(money[i-2]+nums[i], money[i-1]);
        }

        return money[end];
    }
};

// 這題 arranged in a circle 和原本其實都一樣代表相鄰的無法一起加
// 唯一的差別在於 [1,..., n] 中 1 和 n 也是算相鄰所以不能同時放入 array

// 關鍵不是選起點，而是把「第一間和最後一間不能同時偷」拆成兩種情況：
// - 情況 A：必定不偷最後一間 → 偷範圍 [0 ... n-2]
    // 第一間可以偷，也可以不偷 
// - 情況 B：必定不偷第一間 → 偷範圍 [1 ... n-1]
    // 最後一間可以偷，也可以不偷
// 然後對 A 和 B 的 "最後項" 取 max

// 不討論偷第一間和最後一間，而是討論不偷第一間和不偷最後一間。
// 是因為如果討論偷第一間 -> 其實不代表一定會偷第一間


// money[i] = 從第 0 間到第 i 間為止，最多可以偷到多少錢
// money[i] = max(money[i-2]+nums[i], money[i-1])
//  拿這格 or 不拿這格
