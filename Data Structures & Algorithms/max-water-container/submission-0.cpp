class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max_area=0;

        int h=0, w=0; //height & width
        int left=0, right=heights.size()-1;
        while(left < right)
        {
            int tmp = (right-left) * min(heights[left], heights[right]);
            max_area = max(max_area, tmp);

            if(heights[left] < heights[right])
                left++;
            else 
                right--;
        }

        return max_area;
    }
};

// 演算法的核心在於 Greedy 去比較 left 還是 right 哪個比較高？
// 因為一定會減少 => width 必減一， 兩個 height 要越高越好
// 而不是我們 left 跟 left+1 比較，right 跟 right+1 比較。