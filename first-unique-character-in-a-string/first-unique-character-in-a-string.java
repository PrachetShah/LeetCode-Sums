class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> count = new LinkedHashMap<>();
        for(char ch: s.toCharArray()){
            if(count.containsKey(ch)){
                count.put(ch, count.get(ch)+1);
            }else{
                count.put(ch, 1);
            }
        }
        
        for(char x: count.keySet()){
            if(count.get(x) == 1){
                return s.indexOf(x);
            }
        }
        return -1;
    }
}