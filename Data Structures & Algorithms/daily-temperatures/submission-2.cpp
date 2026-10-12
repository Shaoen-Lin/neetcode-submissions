class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> ans(temperatures.size(), 0);

        stack<pair<int,int>> stk;

        stk.push({temperatures.size()-1,temperatures[temperatures.size()-1]});
        for(int i=temperatures.size()-2 ; i>=0 ; --i)
        {
            while(!stk.empty() && temperatures[i] >= stk.top().second)
            {
                stk.pop();
            }
            // 意義：比我小的我一率 pop，因為我比你更大又比你更近。


            if(!stk.empty() && temperatures[i] < stk.top().second) // 代表 stack 裡還是有數字比我大
            {
                ans[i]= stk.top().first - i;
            }

            stk.push({i,temperatures[i]});
        }
        return ans;
    }
};
