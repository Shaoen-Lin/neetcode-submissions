class Solution {
private:
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr = {};
        dfs(s, curr, 0);
        return ans;
    }

    void dfs(string s, vector<string>& curr, int index)
    {
        // if(index == s.size())
        // {
        //     curr.push_back(s[index-1]);
        //     ans.push_back(curr);
        //     curr.pop_back();
        //     return;
        // }
        if(index >= s.size())
        {
            ans.push_back(curr);
            return;
        }

        for(int i=index ; i<s.size() ; ++i)
        {
            if(isPalindrome(s.substr(index, i-index+1)))
            {
                curr.push_back(s.substr(index, i-index+1));
                dfs(s, curr, i+1);
                curr.pop_back();
            }
        }
        return;
    }

    bool isPalindrome(string str)
    {
        int l=0, r=str.size()-1;
        while(l<=r)
        {
            if(str[l] == str[r])
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};

// 根據 i 為 index 每次 Decision Tree 切出前半部跟後半部 
// 然後檢查目前前半部是不是 Palindrome，如果不是就不遞迴下去