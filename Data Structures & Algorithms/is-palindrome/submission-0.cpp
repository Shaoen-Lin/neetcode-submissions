class Solution {
public:
    bool isPalindrome(string s) {
        
        char head;
        char tail;
        // string rev = reverse(s.begin(), s.end());

        string rev = s;
        reverse(rev.begin(), rev.end());

        int i=0, j=0;
        while(i<s.length() && j<s.length())
        {
            head = s[i];
            tail = rev[j];

            while(!inRange(head) && i < s.length()) 
            {
                head = s[++i];
            }

            while(!inRange(tail) && j < rev.length())
            {
                tail = rev[++j];
            }

            if(tolower(head) != tolower(tail))
                return false;

            ++i;
            ++j;
        }
        return true;
    }

    bool inRange(char c)
    {
        if( ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            return true;
        
        return false;
    }
};
