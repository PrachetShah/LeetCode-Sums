class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string out1, out2;
        for(auto x:word1){
            out1 += x;
        }
        for(int i=0; i<word2.size(); i++){
            out2 += word2[i];
        }
        return out1 == out2;
    }
};