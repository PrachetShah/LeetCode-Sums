class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Boolean> check = new HashMap<>();
        for(int num: nums){
            if(check.containsKey(num)){
                return true;
            }
            check.put(num, true);
        }
        return false;
    }
}