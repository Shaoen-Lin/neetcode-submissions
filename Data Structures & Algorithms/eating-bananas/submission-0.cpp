class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int max_pile = -1;
        for(int i=0 ; i<piles.size() ; ++i)
        {
           max_pile = max(max_pile, piles[i]);
        }
        
        // Brute Force
        // for(int i=1 ; i<=piles[piles.size()-1] ; ++i)
        // {
        // }

        // Binary Search
        int ans=INT_MAX;
        int left=1, right=max_pile; // 1 ~ max_pile (因為最多的情況就是每天吃最大 pile 數量)
        while(left <= right)
        {   
            int mid = left + (right-left)/2;

            if(eatable(mid, piles, h))
            {
                ans=min(ans,mid);

                right=mid-1; // mid 不用再跑了，已經記住了
            }
            else
                left=mid+1;
        }
        return ans;
    }

    bool eatable(int rate, vector<int>& piles, int h)
    {
        int time=0;
        for(int i=0 ; i<piles.size() ; ++i)
        {
            time += (piles[i] + rate-1) / rate; // 每一個 pile 要用多少時間 
            // 但取 upper bound + (rate-1)
        }

        if(time <= h)
            return true;
        return false;
    }
};

// piles.size() <= hour <= h
// rate = [1,2,3, ... , max_pile_number]  其實就是跑這個拉

// Brute Force 就是去跑 1 ~ max_pile
// 加速就是 Binary Search 找 rate 可不可以 eatable?
