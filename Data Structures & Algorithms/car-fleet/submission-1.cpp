class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int size=position.size();

        vector<pair<int,int>> cars(size);
        for(int i=0 ; i<size ; ++i)
            cars[i]={position[i], speed[i]};

        sort(cars.begin(), cars.end());

        int ans=1;
        stack<pair<int,int>> stk;
        stk.push(cars[size-1]);
        for(int i=size-2 ; i>=0 ; --i)
        {
            pair<int,int> prev = stk.top();
            float prev_time = (float) (target - prev.first) / (float) prev.second;
            float curr_time = (float) (target - cars[i].first) / (float) cars[i].second;
            
            if(prev_time < curr_time)
            {
                ans++;
                stk.pop();
                stk.push(cars[i]);
            }
            // else => 都不變 
        }
        return ans;
    }
};
// 這題的重點在於要怎麼判斷兩台車會不會是同一個 fleet
// 在於算到終點的時間: time[i] = (target - position[i]) / speed[i]
// 如果 time[i] > time[j] 且 i 的位置在 j 前面 => 那就會是同一個 fleet (然後就必須以 time[i] 的時間為主)
