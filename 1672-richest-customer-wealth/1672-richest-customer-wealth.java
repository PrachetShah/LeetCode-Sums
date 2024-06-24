class Solution {
    public int maximumWealth(int[][] accounts) {
        int richest = 0;
        for(int i=0; i<accounts.length; i++){
            int sum = Arrays.stream(accounts[i]).sum();
            if(sum > richest){
                richest = sum;
            }
        }
        return richest;
    }
}