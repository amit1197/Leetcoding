class Solution {
    public char findTheDifference(String s, String t) {
        char ch=0;
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            ch^=c;
        }
        for(int i=0;i<t.length();i++){
            char c=t.charAt(i);
            ch^=c;
        }
        return ch;
    }
}