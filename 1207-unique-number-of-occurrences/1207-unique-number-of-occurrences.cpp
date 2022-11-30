class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counter;
        for(auto x:arr){
            counter[x]++;
        }
        
        vector<int> x;
        for(auto [key, value]: counter){
            for(int j=0; j<x.size(); j++){
                if(x[j]==value){
                    return false;
                }
            }
            x.push_back(value);
        }
        return true;
    }
};