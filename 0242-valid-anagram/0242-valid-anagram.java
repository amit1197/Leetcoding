class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character,Integer> m=new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            m.put(ch,m.getOrDefault(ch,0)+1);
        }
        for(int i=0;i<t.length();i++){
            char ch=t.charAt(i);
            m.put(ch,m.getOrDefault(ch,0)-1);
        }
        for(int k:m.values()){
            if(k!=0){
                return false;
            }
        }
        return true;
     }
}