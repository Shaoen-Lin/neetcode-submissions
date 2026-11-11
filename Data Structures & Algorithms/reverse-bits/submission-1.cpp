class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t value = 1 << 31;
        uint32_t ans=0;
        for(int i=0 ; i<32 ; ++i)
        {
            bool bit = n & 1;
            
            if(bit == 1)
                ans += value;

            n >>= 1;
            value >>= 1;
        }

        return ans;
    }
};
