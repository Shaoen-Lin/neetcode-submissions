class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ']') // 先遇到
            {   // 看能不能解決 -> stack 不能解決就 false
                if(st.empty() || st.top() != '[') // 避免遇到單獨的右括號還 return true
                    return false;

                st.pop();
            }
            else if(s[i] == '}')
            {
                if(st.empty() || st.top() != '{')
                    return false;

                st.pop();
            }
            else if(s[i] == ')')
            {
                if(st.empty() || st.top() != '(')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};