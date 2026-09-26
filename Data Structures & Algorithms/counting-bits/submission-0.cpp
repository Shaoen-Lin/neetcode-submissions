class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> ans;
        for(int i=0 ; i<=n ; ++i)
        {
            ans.push_back(count(i));
        }

        return ans;
    }

    int count(int n)
    {
        int cnt=0;
        while(n>0)
        {
            cnt += (n&1);
            n >>= 1;
        }

        return cnt;
    }
};
