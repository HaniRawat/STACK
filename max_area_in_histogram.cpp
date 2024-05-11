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

//another solution with same logic
class Solution {
public:

    vector<int> nextSmallerElement(vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--) {
      int curr = arr[i];
      while(s.top() != -1 && arr[s.top()] >= curr) s.pop();
      ans[i] = s.top();
      s.push(i);
    }  
     return ans;
    }

     vector<int> prevSmallerElement(vector<int>& arr, int n) {
         stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
      int curr = arr[i];
      while(s.top() != -1 && arr[s.top()] >= curr) s.pop();
      ans[i] = s.top();
      s.push(i);
    }  
     return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int n = heights.size();
        vector<int> next(n);

        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for(int i=0;i<n;i++) {
            int l = heights[i];
            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};
