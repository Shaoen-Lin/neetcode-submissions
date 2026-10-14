class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>> > mp;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back( {timestamp,value} );
    }

    string get(string key, int timestamp) {
        
        // Brute Force
        // for(int i=mp[key].size()-1 ; i>=0 ; --i)
        // {
        //     if(mp[key][i].first<=timestamp)
        //     {
        //         return mp[key][i].second;
        //     }
        // }
        // return "";


        // Binary Search
        string ans="";
        int left=0, right=mp[key].size()-1;
        while(left <= right)
        {
            int mid = left+(right-left)/2;

            if(mp[key][mid].first<=timestamp) // 目前這個已經找到了，但要去找最大的
            {
                left=mid+1;
                ans = mp[key][mid].second;
            }
            else if(mp[key][mid].first>timestamp)
            {
                right=mid-1;
            }
        }
        return ans;
    }
};

// 目前有兩個問題：
// 1. 要 for 迴圈跑 10^7 通常代表不能用 O(n) 來做
// 2. 以 timestamp 當作 index 也可能需要給到 10^7 的空間造成
    // 如果前一個給 index 1，下一個給 10^7。那就會需要有 10^7 的空間
    // 因此可以用一個特別的處理法 => 把 index 也存進去，變成存 pair。
    // 不要 unordered_map<string, vector<string>> 然後 timestamp 當作第二個 index 
    // 要 mp[key].push_back( {timestamp,value} )