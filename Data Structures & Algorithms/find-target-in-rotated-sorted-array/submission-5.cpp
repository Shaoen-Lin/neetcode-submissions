class Solution {
public:
    int search(vector<int>& nums, int target) {

        // 1.
        int pivot;
        int left=0, right=nums.size()-1;
        while(left <= right)
        {
            if(nums[left]<=nums[right])   // 再次注意 left 有可能 == right
            {
                pivot = left;
                break;
            }

            // 序列不是升序
            int mid=left+(right-left)/2;
            if(nums[left]<=nums[mid])   // mid 在左序列
                left=mid+1;
            else if(nums[left]>nums[mid]) // mid 在右序列
                right=mid;
        }

        // 2. (注意 pivot == 0 之後 -1 會出事 上面要多加上)
        int l_most=0, r_most=nums.size()-1;

        //  pivot == 0 => 沒旋轉
        if(pivot == 0)
            return Binary_Search(l_most, r_most, nums, target);
        // pivot != 0
        if(nums[l_most] <= target)
            return Binary_Search(l_most, pivot-1, nums, target);
        else
            return Binary_Search(pivot, r_most, nums, target);
    }

    int Binary_Search(int left, int right, vector<int>& nums, int target)
    {
        while(left <= right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left=mid+1;
            else if(nums[mid]>target)
                right=mid-1;
        }
        return -1;
    }
};




// 1. 先用 Binary Search 找旋轉切分點，也就是最小值位置
// 2. 根據 target 判斷它應該在左半段還是右半段，再對那一半做一次 Binary Search

// Time O(logn) + O(logn) = O(logn) 

// 2. 
// 已知左序列 > 右序列
// target > leftmost 在左序列
// target < leftmost 在右序列