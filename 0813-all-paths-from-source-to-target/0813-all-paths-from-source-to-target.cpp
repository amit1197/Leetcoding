class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        path.push_back(0);
        queue<vector<int>> q;
        q.push(path);
        while(!q.empty()){
            vector<int> curPath=q.front();
            q.pop();
            int node=curPath.back();
            for(int nbr:graph[node]){
                vector<int> tmpPath(curPath.begin(),curPath.end());
                tmpPath.push_back(nbr);
                if(nbr==graph.size()-1){
                    paths.push_back(tmpPath);
                }
                else{
                    q.push(tmpPath);
                }
            }
        }
        return paths;
    }
};