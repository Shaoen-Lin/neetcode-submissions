class Solution {
public:
    int getSum(int a, int b) {

        int sum;
        int cout;
        while(b != 0)
        {
            sum = a ^ b;
            cout = (a & b) << 1;

            a = sum;
            b = cout;
        }

        return sum;
    }
};