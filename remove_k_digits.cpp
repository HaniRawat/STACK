class Solution {
  public:
    string removeKdigits(string S, int K) {
        int n = S.length();
        if(K==n)
            return "0";
            
        stack<char>st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && K>0 && st.top() > S[i]){
                st.pop();
                K--;
            }
            st.push(S[i]);
        }
        
        while(K>0){
            st.pop();
            K--;
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        int i;
        
        for(i = 0; i<ans.size();i++){
            if(ans[i] !='0'){
                break;
            }
        }
        if(i == ans.size()){
            return "0";
        }
        return ans.substr(i);
    }
};