#include<iostream>
#include<stack>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        if(x.length() == 1)
            return false;
            
        stack<char>st;
        
        for(int i=0;i<x.length();i++){
            if(x[i] == '(' || x[i] == '{' || x[i] == '[')
                st.push(x[i]);
                
            else if(x[i] == ')'){
                if(st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            
            else if(x[i] == ']'){
                if(st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            
            else if(x[i] == '}'){
                if(st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
        }
    return st.empty();
    }

};

