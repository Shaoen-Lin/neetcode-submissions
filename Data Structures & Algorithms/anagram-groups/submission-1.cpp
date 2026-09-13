class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int cnt[10000][26] = {0}; // a=0, b=0, c=0
        int vec_length = strs.size();

        // 計算 cnt 陣列
        for(int i=0 ; i< vec_length ; ++i)
        {
            for(int j=0 ; j< strs[i].length() ; ++j)
            {
                cnt[i][strs[i][j] - 'a']++;
            }
        }

        // 分組：轉換 cnt 成 key value => unordered_map 幫助轉換 + 分組
        // 轉換成 [1,3,0,2,...] => {1302} 但這樣會看不出來 13 or 1、3 => 所以 {1#3#0#2#...} 
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < vec_length; ++i)
        {
            string key = "";

            // 把 cnt[i][j] 加入 key
            for (int j = 0; j < 26; ++j)
            {
                key += to_string(cnt[i][j]);
                key += '#';
            }

            mp[key].push_back(strs[i]); // 根據這個 key 放入 strs[i]
        }

        // 取答案了
        vector<vector<string>> ans;
        for (auto& pair : mp) // auto 是型態，pair 是每一組對應
        {
            ans.push_back(pair.second); // second 是每個 key 指的東西， first 是 key
        }

        return ans;
    }
};
