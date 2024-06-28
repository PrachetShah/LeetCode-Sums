class Solution {
    public void moveZeroes(int[] nums) {
        int lastZeroNotFound = 0;
        for(int i=0; i<nums.length; i++){
            if(nums[i] != 0){
                int temp = nums[i];
                nums[i] = nums[lastZeroNotFound];
                nums[lastZeroNotFound] = temp;
                lastZeroNotFound++;
            }
        }
    }
}