int Solution::braces(string A) {

    stack<char>s;

    bool isredundant = 0;

    for(int i=0; i<A.size(); i++){

        if(A[i]=='(') {

            s.push(A[i]);

        }

        else if (!s.empty() and (A[i]=='+' or A[i]=='*' or A[i]=='-' or A[i]=='/'))

        s.push(A[i]);

        else{

            if(A[i]==')')

           {

               bool flag = true;

               while(!s.empty() && s.top() != '('){

                   if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'){

                       flag = false;

                   }

                   s.pop();

               }

               if(flag){

                   isredundant = 1;

                   break;

               }

               s.pop();

           }

        }

    }

    return isredundant;

}