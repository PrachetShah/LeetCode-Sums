class Solution {
public:
    int calculate(string s) {
        int acc=0, curr_num=0, sign=1;
        vector<vector<int>> stack;

        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ')
                continue;
            else if(s[i] >= 48 && s[i] <= 57){
                curr_num = curr_num*10+(s[i]-48);
            }else if(s[i] == '+' || s[i] == '-'){
                acc += sign*curr_num;
                curr_num = 0;
                sign = (s[i] == '+')*2-1;
            }else if(s[i] == '('){
                stack.push_back({acc, sign});
                sign = 1;
                acc = 0;
            }else if(s[i] == ')'){
                acc += sign*curr_num;
                acc *= stack.back()[1];
                acc += stack.back()[0];
                stack.pop_back();
                curr_num = 0;
                sign = 1;
            }
        }

        return acc + sign*curr_num;
    }
};