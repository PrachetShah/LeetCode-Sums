class Solution {
    public int removeDuplicates(int[] nums) {
        int index = 0;
        for(int i=0; i<nums.length; i++){
            if(nums[i] != nums[index]){
                index++;
                nums[index] = nums[i]; 
            }
        }
        return index+1;
    }
}