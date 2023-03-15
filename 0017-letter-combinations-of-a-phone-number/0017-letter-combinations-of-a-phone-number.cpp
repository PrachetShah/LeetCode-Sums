class Solution {
public:
    void solve(string digits, string output, int index, vector<string>& ans, string mapping[]){
        // base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        
        int number = digits[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, mapping);
            // once it comes back it will again add previous char from again 
            //for eg: 1) a, 2)ab, back) aba  then return
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        if(digits.length() == 0){
            return ans;
        }
        int index=0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};