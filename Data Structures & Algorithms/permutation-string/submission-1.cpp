class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> map;
        for(int i=0 ; i<s1.length() ; ++i)
            map[s1[i]]=0;

        // initialize
        for(int i=0 ; i<s1.length() ; ++i)
            map[s1[i]]++;


        // xx.length() 會回傳 size_t 導致拿去跟 i 比較會 underflow 變一個超大的數
        // 因此 s2.length()-s1.length() 只要是負數就會錯 -> 多加檢查

        if(s1.length() > s2.length())
            return false; 

        for(int i=0 ; i<=s2.length()-s1.length() ; ++i)
        {
            unordered_map<char,int> tmp_map = map;

            if(tmp_map.count(s2[i]))
            {
                for(int j=0; j<s1.length() ; ++j)
                {
                    if(tmp_map.count(s2[i+j]) && tmp_map[s2[i+j]]>0)
                        tmp_map[s2[i+j]]--;
                    else 
                        break;

                    if(tmp_map[s2[i+j]]==0)
                        tmp_map.erase(s2[i+j]);  
                }

                if(tmp_map.empty())
                    return true;
            }
        }

        return false;
    }
};
