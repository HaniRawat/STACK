class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long ans = 0;
        
        long long i = 0;
        long long j = N-1;
        
        while(i<j){
            ans = max(ans, arr[i]+arr[i+1]);
            i++;
        }
        
        return ans;
    }
};