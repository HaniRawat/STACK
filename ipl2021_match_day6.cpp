class Solution{
    public:
    vector<int> form_lps(string s){
        int n = s.size();
        vector<int> v(n);
        
        int i = 0;
        for(int j = 1; j < n; j++){
            while(i!=0 && s[i] != s[j]){
                i = v[i-1];
            }
            if(s[i] == s[j]){
                v[j] = i+1;
                i+=1;
            }
        }
        return v;
    }
    string compress(string s)
    {
        int n = s.size();
        vector<int> v = form_lps(s);
        
        string st = "";
        int i = n;
        while(i){
            if(i&1){
                st.push_back(s[i-1]);
                i-=1;
            }
            else{
                if(v[i-1] >= i/2){
                    if(i%(2*(i-v[i-1])) == 0){
                        st.push_back('*');
                        i/=2;
                    }
                    else{
                        st.push_back(s[i-1]);
                        i-=1;
                    }
                }
                else{
                    st.push_back(s[i-1]);
                    i-=1;
                }
            }
        }
        reverse(st.begin(),st.end());
        return st;
    }
};