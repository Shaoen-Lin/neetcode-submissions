class Solution {
public:
    int getSum(int a, int b) {
        return adder(a,b);
    }

    // 這題特別的地方在於不用特地去做每個 bit 的 adder，可以全部一起做
    int adder(int a, int b)
    {
        int sum = a^b;
        int carry = (a&b) << 1;
    
        if(carry != 0)
            return adder(sum, carry);
        else
            return sum;
    }
};

// 這題不用做 two's complement 了 因為 ex. -3 在系統其時就是 101
