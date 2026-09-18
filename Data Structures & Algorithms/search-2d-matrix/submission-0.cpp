class Solution {
public:
    // 想到這題 index 還是可以正常在二維陣列跑 => 可以先處理 row 和 col
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row =matrix.size(), col=matrix[0].size(); // 背好這個寫法

        int left=0, right=row*col-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(matrix[mid/col][mid%col] == target)
                return true;
            else if(matrix[mid/col][mid%col] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return false;
    }
};
