class Solution {
private:
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if(digits != "")
        {
            vector<vector<char>> map(10, vector<char>(4));
            map[2]={'a', 'b', 'c'};
            map[3]={'d', 'e', 'f'};
            map[4]={'g', 'h', 'i'};
            map[5]={'j', 'k', 'l'};
            map[6]={'m', 'n', 'o'};
            map[7]={'p', 'q', 'r', 's'};
            map[8]={'t', 'u', 'v'};
            map[9]={'w', 'x', 'y', 'z'};

            string curr = "";
            dfs(digits, curr, 0, map);
        }
            
        return ans;
    }

    // index 代表到第幾 digit
    void dfs(string digits, string& curr, int index, vector<vector<char>>& map)
    {   
        if(index == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        int digit = digits[index] - '0';
        for(int i=0 ; i<map[digit].size() ; ++i)
        {
            curr += map[digit][i];
            dfs(digits, curr, index+1, map);
            curr.erase(curr.size()-1);
        }
        return;
    }
};
