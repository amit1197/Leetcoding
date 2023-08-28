class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxi=0;
        for(int[] row:accounts){
            int s=0;
            for(int r:row){
                s+=r;
            }
            maxi=Math.max(maxi,s);
        }
        
        return maxi;
    }
}