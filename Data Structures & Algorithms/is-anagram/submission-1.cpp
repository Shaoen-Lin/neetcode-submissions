class Solution {

private:
    char num_char[26] = {0}; // 0 = a, 1 = b ...
public:
    bool isAnagram(string s, string t) {

        // default s 和 t 的長度一樣
        if(s.length() != t.length())
        {
            return false;
        }
        else
        {
            for(int i=0 ; i<s.length() ; ++i)
            {
                num_char[ s[i] - 'a']++;
            }

            for(int i=0 ; i<s.length() ; ++i)
            {
                num_char[ t[i] - 'a']--;
            }
        
            for(int i=0 ; i<26 ; ++i)
            {
                if(num_char[i] != 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
};
