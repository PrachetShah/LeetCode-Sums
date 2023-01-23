class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> char_set;
        
        for(int n: nums){
            int val = n;
            if(char_set[val]){
                return true;
            }
            char_set[val]=true;
        }
        return false;
    }
};