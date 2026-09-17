class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;

        int left=0, right=numbers.size()-1; // pointer，這樣訂就可以讓兩個指標往單一方向移動
        while(left < right)
        {
            if(numbers[left] + numbers[right] == target)
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
            else if(numbers[left] + numbers[right] < target) //太小了，left 往右移
                left++;
            else // 太大了，right 左移
                right--;
        }
        return ans;
    }
};
