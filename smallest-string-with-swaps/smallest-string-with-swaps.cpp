class UnionFind {
    private:
    vector<int> root;
    vector<int> rank;
    public:
    UnionFind(int sz):root(sz),rank(sz){
        for(int i=0;i<sz;i++) {
            root[i]=i;
            rank[i]=1;
        }
    }
    int find(int x){
        cout<<"e. ";
        if(x==root[x]){
            return root[x];
        }
        return root[x]=find(root[x]);
    }
    void unionSet(int x,int y){
        cout<<"d. ";
        int rootX=find(x);
        int rootY=find(y);
        if(rank[rootX]>rank[rootY]){
            root[rootY]=rootX;
        }
        else if(rank[rootX]<rank[rootY]){
            root[rootX]=rootY;
        }
        else{
            root[rootY]=rootX;
            rank[rootX]+=1;
        }
    }
    map<int,vector<int>> components(){
        map<int,vector<int>> m;
        for(int i=0;i<root.size();i++){
            m[find(i)].push_back(i);
        }
        return m;
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        cout<<"h"<<" ";
        UnionFind uf(s.size());
        cout<<"h1. ";
        for(int i=0;i<pairs.size();i++){
            uf.unionSet(pairs[i][0],pairs[i][1]);
        }
        cout<<"hello1"<<" ";
        map<int,vector<int>> m;
        m=uf.components();
        string res = "";
        vector<char> c(s.size());
        map<int,vector<char>> m1;
        cout<<"hello2"<<" ";

        for(auto i:m){
            for(int j=0;j<i.second.size();j++){
                m1[i.first].push_back(s[i.second[j]]);
            }
            sort(m1[i.first].begin(),m1[i.first].end());
            for(int j=0;j<i.second.size();j++){
                c[i.second[j]]=m1[i.first][j];
            }
            
        }
        cout<<" hello";
        for(auto i:c){
            cout<<i<<" ";
            res+=i;
        }
        return res;
        
        
    }
};