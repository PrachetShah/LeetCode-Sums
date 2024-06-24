class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] alphabet = new int[26];
        for(char c: ransomNote.toCharArray()){
            int i = magazine.indexOf(c, alphabet[c%26]);
            // not present in magazine
            if(i==-1){
                return false;
            }
            alphabet[c%26] = i + 1;
        }
        return true;
    }
}