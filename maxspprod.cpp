int Solution::maxSpecialProduct(vector<int> &A) {

    vector<int> right(A.size(),0);

    vector<int> left(A.size(),0);   

    stack<int> s;

    s.push(0);

    for(int i=1;i<A.size();i++){

        while(!s.empty() and A[s.top()] <= A[i] )
            s.pop();

        if(!s.empty())
            left[i] = s.top();

        else left[i] = 0;

        s.push(i);

    }


    stack<int>s2;

    s2.push(A.size()-1);

     for(int i=A.size()-2;i>=0;i--){

        while(!s2.empty() and A[s2.top()] <= A[i] )
            s2.pop();

        if(!s2.empty())
            right[i] = s2.top();

        else right[i] = 0;

        s2.push(i);

    }

    long long ans=0;

    int mod = 1e9+7;

    for(int i=0;i<left.size();i++){

        ans = max(ans, 1LL*left[i]*right[i]);

        ans%=mod;

    }

    return ans%mod;

}