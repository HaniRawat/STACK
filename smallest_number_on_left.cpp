class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) {
            
            int val = a[i];

            if(s.top()!=-1 && val<= s.top()) {
                while(s.top() >=val) {
                    s.pop();
                }
            }
            
            ans[i] = s.top();
            s.push(val);
            
            
        }
        
        return ans;
    }
};