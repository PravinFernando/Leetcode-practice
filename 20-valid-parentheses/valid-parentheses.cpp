class Solution{
    public:
        bool isValid(string s){//{[()]}
            stack<char> st;
            for(char ch:s){//01234
                if(ch=='(' || ch=='{'||ch=='['){
                    st.push(ch);//{-push [-push (-push
                }else{
                    if(st.empty()) return false;
                    if((ch==')'&&st.top()!='(')||(ch=='}'&&st.top()!='{')||(ch==']'&& st.top()!='[')){
                   return false; }st.pop();
                }
            }//true or false
        return st.empty();}
};