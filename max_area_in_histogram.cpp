class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {

        long long ans = 0;
        
        stack<int>st;        
        
        for(int i=0; i<n; i++){
            if(st.empty())
                st.push(i);
            else if(arr[st.top()] <= arr[i]){
                st.push(i);
            }
            else{
                int index = st.top();
                st.pop();
                if(st.empty()){
                    ans = max(ans, arr[index]*(i));
                }
                else{
                    ans = max(ans, arr[index]*(i-st.top()-1));
                }
            i--;
            }
        }
        while(!st.empty()){
            int index = st.top();
            st.pop();
            if(st.empty()){
                ans = max(ans, arr[index]*n);
            }
            else{
                ans = max(ans,arr[index]*(n-st.top()-1));
            }
        }
        return ans;
    }
};
