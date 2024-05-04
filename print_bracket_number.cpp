class Solution{
public:	

	vector<int> bracketNumbers(string S)
	{
	    // Your code goes here
	    int count = 0;
	    stack<int>st;
	    vector<int>v;
	    
	    for(int i=0; i<S.length();i++){
	        if(S[i] == '('){
	            count++;
	            v.push_back(count);
	            st.push(count);
	        }
	        else if(S[i] == ')'){
	            v.push_back(st.top());
	            st.pop();
	        }
	    }
	    return v;
	}
};