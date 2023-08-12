class UnionFind {
    private:
        vector<int> root;
        vector<int> rank;
    public:
        UnionFind(int sz):root(sz),rank(sz){
            for(int i=0;i<sz;i++){
                root[i]=i;
                rank[i]=1;
            }
        }
        int find(int x){
             if(x==root[x]){
                 return x;
             }
             return root[x]=find(root[x]);
        }
        void unionSet(int x, int y){
            int rootX=find(x);
            int rootY=find(y);
            if(rank[x]>rank[y]){
                root[rootY]=rootX;
            }
            else if(rank[x]<rank[y]){
                root[rootX]=rootY;
            }
            else{
                root[rootY]=rootX;
                rank[rootX]+=1;
            }
            
        }
        int noOfProvinces(){
            set<int> s;
            for(int i=0;i<root.size();i++){
                // cout<<find(i)<<" ";
                s.insert(find(i));
            }
            return s.size();
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
         UnionFind uf(isConnected.size());
         for(int i=0;i<isConnected.size();i++){
             for(int j=0;j<isConnected[i].size();j++){
                 if(isConnected[i][j]==1){
                     uf.unionSet(i,j);
                 }
             }
         }
         return uf.noOfProvinces();
         
    }
};