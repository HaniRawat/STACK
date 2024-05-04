class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {

    stack<int> stack;
    

    for(int num : arr) {

        if(stack.empty()) {
            stack.push(num);
        } else {
         
            if((stack.top() >= 0 && num < 0) || (stack.top() < 0 && num >= 0)) {
                stack.pop();
            } else {
                stack.push(num);
            }
        }
    }

    vector<int> result;

    while(!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }
    
    reverse(result.begin(), result.end());
    
    return result;
    }
};