class Solution {
public:
    int clumsy(int n) {
        int i=0;
        stack<int>s, ans;
        s.push(n);
        n--;

        while(n){
            //multiply
            if(i == 0){
                int num = s.top();
                s.pop();
                s.push(num*n);
            }
            else if(i == 1){
                int num = s.top();
                s.pop();
                s.push(num/n);
            }
            else{
                s.push(n);
            }
            i = (i+1)%4;
            n--;
        }
        while(!s.empty()){
            ans.push(s.top());
            s.pop();
        }
        long long sum = ans.top();
        ans.pop();
        bool flag = 0;
        while(!ans.empty()){
            if(flag == 0){
                sum+=ans.top();
            }
            else{
                sum-=ans.top();
            }
            ans.pop();
            flag = !flag;
        }
        return sum;
    }
};