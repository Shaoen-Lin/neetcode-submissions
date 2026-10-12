class Solution {
private:
    stack<int> stk;
public:
    int evalRPN(vector<string>& tokens) {

        
        for(int i=0 ; i<tokens.size() ; ++i)
        {
            if(!isOperator(tokens[i])) // 不是 Notation
                stk.push(stoi(tokens[i]));
            else
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                int tmp=0;
                if(tokens[i] == "+")
                    tmp = a+b;
                else if(tokens[i] == "-")
                    tmp = a-b;
                else if(tokens[i] == "*")
                    tmp = a*b;
                else if(tokens[i] == "/")
                    tmp = a/b; 

                stk.push(tmp);  
            }
        }   
        return stk.top();
    }

    bool isOperator(string c)
    {
        if(c == "+" || c == "-" || c == "*" || c == "/")
            return true;

        return false;
    }
};
