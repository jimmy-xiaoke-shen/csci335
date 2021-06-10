# LeetCode [150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

```cpp
class Solution {
public:
    int evaluate(string token,int a, int b){
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        if (token == "/") return a / b;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        /*
        tokens = ["2","5","+","3","*"]
        stk= []
        for 2 and 1:
        stk = [2, 5]
        for +:
        + is an operator, we should do something
        a = 2, b = 5
        temp_ret = a + b = 7
        stk = [7]
        for 3:
         stk = [7, 3]
         for "*"
         a = 7, b = 3
         temp_ret = a*b = 21
         stk = [21]
         return stk.back()
        */
        vector<int> stk;
        int a, b;
        int temp_ret;
        for (auto token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                b = stk.back(); stk.pop_back();
                a = stk.back(); stk.pop_back();
                temp_ret = evaluate(token, a, b);
                stk.push_back(temp_ret);
            } else {
                stk.push_back(stoi(token));
            }
        }
        return stk.back();
    }
};
```
