class Solution {
    public int reverse(int x) {
        int num = Math.abs(x);
        int finalRes = 0;
        while(num!=0){
            int tail = num%10;
            
            // overflow check
            if(finalRes > (Integer.MAX_VALUE-tail)/10){
                return 0;
            }
            finalRes = finalRes*10 + tail;
            num = num/10;
        }
        
        return (x < 0) ? (-finalRes) : finalRes;
    }
}