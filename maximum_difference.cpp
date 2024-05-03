class Solution{  
  public:

    int findMaxDiff(vector<int> &arr, int n) {

        stack<int>st;
        
        //left smaller
        int ls[n],rs[n];
        
        for(int i=0;i<n;i++){
            int t = arr[i];
            while(!st.empty() && st.top() >= t){
                st.pop();
            }
            
            if(st.empty())
                ls[i]=0;
            else{
                ls[i] = st.top();
            }
            st.push(t);
        }
        while(!st.empty()) st.pop();
        
        //right smaller
        for(int i = n-1; i>=0; i--){
            int t = arr[i];
            while(!st.empty() && st.top() >= t){
                st.pop();
            }
            if(st.empty())
                rs[i] = 0;
            else{
                rs[i] = st.top();
            }
            st.push(t);
        }
        
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx, abs(ls[i] - rs[i]));
        }
        return mx;
    }
};