class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         Boyer-Moore Voting
        int count = 0;
        int candidate = 0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
            }
            count += (nums[i]==candidate)?1:-1;
        }
        return candidate;
//         Hashmap
        // map<int, int> counter;
        // for(int i=0; i<nums.size(); i++){
        //     counter[nums[i]]++;
        // }
        // int num = nums[0];
        // for(auto i: counter){
        //     if(counter[num] < counter[i.first]){
        //         num = i.first;
        //     }
        // }
        // return num;
    }
};