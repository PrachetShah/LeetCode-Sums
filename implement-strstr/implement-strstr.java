class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length() > haystack.length()){
            return -1;
        }
 
        List<Integer> indexes = new ArrayList<>();
        
        for(int i=0; i<haystack.length() - needle.length() + 1; i++){
            if(haystack.charAt(i) == needle.charAt(0)){
                indexes.add(i);
            }
        }
        
        for(int index: indexes){
            int start = index;
            boolean isBreak = false;
            for(int i=0; i<needle.length(); i++){
                if(haystack.charAt(start) != needle.charAt(i)){
                    isBreak = true;
                    break;
                }else{
                    start++;
                }
            }
            if(!isBreak){
                return index;
            }
        }
        
        return -1;
        
        
        /*
        USING JAVA Inbuilt Methods
        
        for(int i = 0, j = needle.length(); j<=haystack.length(); i++,j++){
            if(haystack.substring(i,j).equals(needle)){
                return i;
            }
        }
        return -1;
        */
    }
}