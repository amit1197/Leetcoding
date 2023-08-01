class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        for(int i=0;i<og.size();i++){
            for(int j=0;j<og[0].size();j++){
                if(og[i][j]==1) og[i][j]=-1;
            }
        }
        if(og[0][0]!=-1) og[0][0]=1;
        for(int i=1;i<og.size();i++){
            if(og[i][0]!=-1)
                og[i][0]=og[i-1][0];
        }
        for(int i=1;i<og[0].size();i++){
            if(og[0][i]!=-1)
                og[0][i]=og[0][i-1];
        }
        for(int i=1;i<og.size();i++){
            for(int j=1;j<og[0].size();j++){
                if(og[i][j]!=-1){
                    if(og[i-1][j]!=-1){
                        og[i][j]+=og[i-1][j];
                    }
                    if(og[i][j-1]!=-1){
                        og[i][j]+=og[i][j-1];
                    }
                }
            }
        }
        return og[og.size()-1][og[0].size()-1]==-1?0:og[og.size()-1][og[0].size()-1];

    }
};