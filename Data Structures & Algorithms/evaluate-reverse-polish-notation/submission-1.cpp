class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(auto it : tokens)
        {
            if(isdigit(it.back()))
            {
                st.push(it);
            }
            else 
            {
                string second = st.top();
                st.pop();
                string first = st.top();
                st.pop();
                int ss = stoi(second);
                int ff = stoi(first);
                if(it == "+") ff += ss;
                if(it == "-") ff -= ss;
                if(it == "*") ff *= ss;
                if(it == "/") ff /= ss;
                string now = to_string(ff);
                st.push(now);
            }
        }
        string val = st.top();
        return stoi(val);
    }
};
