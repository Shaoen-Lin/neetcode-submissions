class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;

        int prev=prices[0];
        int curr;
        for(int i=1 ; i<prices.size() ; ++i)
        {
            curr=prices[i];

            if(curr<prev)
            {
                prev=curr;
            }
            else
            {
                ans+=curr-prev;
                prev=curr;
            }
        }
        return ans;
    }
};