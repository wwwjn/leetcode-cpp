class Solution {
public:
    int calculate(string s) {
        char op = '+';
        stack<long> st;
        long num = 0;
        for(int i = 0; i< s.size(); i++){
            // if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <='9'){
                num = num * 10 + s[i] - '0';
            }
            if((s[i] < '0' && s[i] != ' ') || i == s.size()-1) {
                if(op == '+' || op == '-'){
                    if(op == '+') st.push(num);
                    else st.push(-num);
                }else if(op == '*'){
                    long num1 = st.top();
                    st.pop();
                    st.push(num * num1);
                    cout << num << " " << num1 << endl;
                }else{
                    long num1 = st.top();
                    st.pop();
                    st.push(num1/num);
                    cout << num << " " << num1 << endl;
                }
                op = s[i];
                num = 0;
            }
        }
        int sum = 0;
        while(!st.empty()){
            cout << st.top() << endl;
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};