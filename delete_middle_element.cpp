class Solution
{
    public:
    void solve(stack<int>&s, int size, int count){
        if(count == size/2){
            s.pop();
            return;
        }
        
        int element = s.top();
        s.pop();
        solve(s,size,count+1);
        s.push(element);
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0;
        solve(s,sizeOfStack,count);
    }
};