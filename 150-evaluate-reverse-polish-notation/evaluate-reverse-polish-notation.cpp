class Solution {
public:
  int solve(string p,int a,int b){
    if(p=="+")return (a+b);
    if(p=="*")return (a*b);
    if(p=="-")return (a-b);
    return (a/b);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
            if(it=="+"||it=="-"||it=="/"||it=="*"){
                int sec=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                int ans=solve(it,first,sec);
                st.push(ans);
            }
            else st.push(stoi(it));
            
        }
        return st.top();
    }
};