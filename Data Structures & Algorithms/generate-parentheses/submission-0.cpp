class Solution {
private:
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, "", 0, 0);
        return ans;
    }

    void dfs(int n, string substring, int left, int right)
    {
        if(left == n)
        {
            while(substring.size() < 2*n)
            {
                substring += ")";
            }
            ans.push_back(substring);
            return;
        }

        substring += "(";
        dfs(n, substring, left+1, right);
        substring.erase(substring.size()-1);

        if(left > right)
        {
            substring += ")";
            dfs(n, substring, left, right+1);
            substring.erase(substring.size()-1);
        }
        
        return;
    }
};
