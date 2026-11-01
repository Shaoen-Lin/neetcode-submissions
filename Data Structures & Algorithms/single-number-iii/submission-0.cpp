class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int val=0;
        for(int num : nums)
        {
            val ^= num;
        }

        // Partition
        int lowbit = val & (-val);
        int x=0, y=0;
        for(int num : nums)
        {
            if((num & lowbit) == lowbit)
                x ^= num;
            else
                y ^= num;     
        }

        return {x,y};
    }
};

// 1. 全體 XOR：遍歷陣列，計算所有元素的總 XOR 值 
// 2. 尋找最低位的 1：利用 lowbit = X & (-X) 取得 X 中最右邊的 1。
// 3. 分組並求值：再次遍歷陣列，根據每個數字與 lowbit 做 & 運算的結果分成兩組，分別累積 XOR 值。
// 4. 回傳結果：回傳這兩個累積出的答案。