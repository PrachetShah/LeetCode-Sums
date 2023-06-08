class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> counter;
        for(int i=0; i<nums.size(); i++){
            counter[nums[i]]++;
        }
        int num = nums[0];
        for(auto i: counter){
            if(counter[num] < counter[i.first]){
                num = i.first;
            }
        }
        return num;
    }
};