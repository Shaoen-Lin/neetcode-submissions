class Solution {
public:

    // 這個沒有空間的缺陷 => 因為改成數到中間就停止 

    bool isPalindrome(string s) {
        int left=0, right=s.length() - 1;
        // 長度是 odd => left == right; 長度是 even => left > right 為終止條件
        while(left < right)
        {
            char head = s[left];
            char tail = s[right];

            while(left < right && !inRange(head)) 
            {
                head = s[++left];
            }

            while(left < right && !inRange(tail)) 
            {
                tail = s[--right];
            }

            if(tolower(head) != tolower(tail))
                return false;

            ++left;
            --right;
        }
        return true;
    }

    // 自製的 isalnum
    bool inRange(char c)
    {
        if( ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            return true;
        
        return false;
    }
};
