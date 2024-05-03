void sortStack(stack<int>& s,int num){
    if(s.empty() || s.top()<num){
        s.push(num);
        return;
    }
    int ele = s.top();
    s.pop();
    
    sortStack(s,num);
    
    s.push(ele);
}
void solve(stack<int>& s){
    if(s.empty()){
        return;
    }
    int ele = s.top();
    s.pop();
    
    solve(s);
    sortStack(s,ele);
}

void SortedStack :: sort()
{
   //Your code here
   solve(s);
}