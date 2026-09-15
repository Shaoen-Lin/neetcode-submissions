class Solution {
public:

    string encode(vector<string>& strs) {

        string new_str = "";
        for(int i=0 ; i<strs.size() ; ++i)
        {
            new_str += to_string(strs[i].length());
            new_str += "#";
            new_str += strs[i];
        }

        return new_str;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        int length = 0;
        for(int i=0 ; i<s.length() ; ++i)
        {
            if(s[i] == '#')
            {
                string ori = "";
                for(int j=0; j<length ; ++i,++j) // 因為 # 多數一個
                {
                    ori += s[i+1];
                }

                ans.push_back(ori);
                length = 0;
            }
            else 
            {
                length *= 10;
                length += (int)(s[i] - '0');
            }                   
        }
        return ans;
    }
};

// ori: "Hello", "World"
// encoded: "5#Hello5#World"