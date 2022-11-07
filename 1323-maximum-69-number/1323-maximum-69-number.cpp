class Solution {
public:
    int maximum69Number (int num) {
        string numString = to_string(num);
        for(auto &currchar: numString){
            if(currchar == '6'){
                currchar = '9';
                break;
            }
        }
        return stoi(numString);
    }
};