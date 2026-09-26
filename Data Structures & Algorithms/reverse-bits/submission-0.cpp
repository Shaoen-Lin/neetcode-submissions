class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t val= 1u << 31; // 就是 2^31
        uint32_t ans=0;
        for(int i=0 ; i<32 ; ++i)
        {
            if(n&1u)
                ans += val; 

            val >>= 1;
            n >>= 1;
        }
        return ans;
    }
};
