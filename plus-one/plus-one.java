class Solution {
    public int[] plusOne(int[] digits) {
        if(digits[digits.length-1] < 9){
            digits[digits.length-1]++;
            return digits;
        }else{
            int increment = digits.length-1;
            while(increment>=0 && digits[increment] == 9){
                digits[increment] = 0;
                increment--;
            }
            // if increment is greater than 1 than add one else add 1 in beginnning
            if(increment >= 0){
                digits[increment]++;
                return digits;
            }else{
                int[] res = new int[digits.length+1];
                res[0] = 1;
                for(int i=0; i<digits.length; i++){
                    res[i+1] = digits[i];
                }
                return res;
            }

        }
    }
}