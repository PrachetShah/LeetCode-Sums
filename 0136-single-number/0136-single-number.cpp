class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> store;
        for(auto num: nums){
            store[num]++;
        }
        for(auto num: store){
            if(num.second==1){
                return num.first;
            }
        }
        return 0;
    }
};