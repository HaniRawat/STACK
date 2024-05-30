int Solution::trap(const vector<int> &A) {
    vector<int>left,right;
    
    int leftm = INT_MIN;
    int rightm = INT_MIN;
    
    int n = A.size();
    for(int i = 0; i<n; i++){
        leftm = max(leftm, A[i]);
        left.push_back(leftm);
        rightm = max(rightm, A[n-i-1]);
        right.push_back(rightm);
    }
    
    reverse(right.begin(), right.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        if(left[i]<right[i])
            ans += left[i] - A[i];
        else
            ans += right[i]-A[i];
    }
    return ans;
}
