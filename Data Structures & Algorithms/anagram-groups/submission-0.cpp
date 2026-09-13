class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); ++i)
        {
            int cnt[26] = {0};

            for (int j = 0; j < strs[i].size(); ++j)
            {
                cnt[strs[i][j] - 'a']++;
            }

            string key = "";

            for (int j = 0; j < 26; ++j)
            {
                key += to_string(cnt[j]);
                key += '#';
            }

            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for (auto& pair : mp)
        {
            ans.push_back(pair.second);
        }

        return ans;
    }
};