class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;

        for(int i = 0; i<operations.size();i++){
            if(st.empty())
                st.push(stoi(operations[i]));
            else{
                if(operations[i] == "+"){
                    int num1 = st.top();
                    st.pop();

                    int num2 = st.top();
                    st.push(num1);
                    st.push(num1 + num2);
                }
                else if(operations[i] == "C"){
                    st.pop();
                }
                else if(operations[i] == "D"){
                    st.push(2*st.top());
                }
                else{
                    st.push(stoi(operations[i]));
                }
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
        
    }
};