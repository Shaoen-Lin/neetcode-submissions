class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq(stones.begin(), stones.end());

        // for(int stone : stones)
        //     pq.push(stone);

        while(pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if(a-b > 0)
                pq.push(a-b);
        }

        if(pq.empty())
            return 0;
        return pq.top();
    }
};

// Time: O()