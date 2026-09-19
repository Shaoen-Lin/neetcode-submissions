class Solution {
public:
    int findMin(vector<int> &nums) {

        int left=0, right=nums.size()-1, mid;

        while(left <= right) // 因為 left 和 right 在同一格的時候，還需要跑最後一輪
        {
            if(nums[left] <= nums[right]) // 有等於是因為有可能 left 和 right 在同一格的時候
                return nums[left];

            // 注意！數列的數字是 unique 不代表下面 "等於的情形" 不用討論，因為 mid 有可能和 left 指到同一個

            int mid = left + (right-left)/2; // 代表 mid 還在 左邊序列
            if(nums[left] < nums[mid])
                left = mid+1;
            else if(nums[left] > nums[mid]) // 代表 mid 已在 右邊序列
                right = mid;
            else    // mid 和 left 指到同一個 只有可能是 [x,y] 的情形 又 nums[left] > nums[right]
                return nums[right];

        }
    }
};

// 分的時候只要就是去判斷 nums[mid] 現在在裡面左邊還是右邊序列裡面
// 我們也知道 左邊序列 必定大於 右邊序列 && 答案必在右邊序列
// 邏輯：
// 1. 如果最左邊的數字 nums[left] < nums[mid] -> 代表 left 到 mid 是上升序列 -> mid 還在 左邊序列
// -> 答案在右邊序列 -> left = mid+1 (因為 mid 必不是 ans 所以可以把它排除)

// 2. 如果最左邊的數字 nums[left] > nums[mid] -> 代表 left 和 mid 是不同序列 -> mid 已在 右邊序列
// -> 已知 mid 的右邊不會是答案 (但注意！ mid 自己可能是答案) -> right = mid （不能 = mid-1 因為不能把 mid 排除）
// 但這裡也知道 left 不會是 ans 所以 -> 也可以 left++ 限縮範圍

// 我們主要想做的是 
// nums[mid] >= nums[left]
// → minimum ∈ [mid+1, right]

// nums[mid] < nums[left]
// → minimum ∈ [left, mid]

// Example:
// [3,4,5,0,1,2] -> [0,1,2] -> return 0
// [3,4,0,1,2] -> [3,4,0] -> [0] -> return 0
// [3,4,5,6,1,2] -> [6,1,2] -> [6,1] -> [1] -> return 1
            
