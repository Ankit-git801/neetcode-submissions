class Solution {
public:
bool dfs(vector<vector<int>>&adj,int u,vector<bool>&vis,vector<bool>&cur){
    vis[u]=true;
    cur[u]=true;
    for(int &x:adj[u]){
        if(!vis[x]){
            if(!dfs(adj,x,vis,cur))
            return false;
        }
        else{
            //cycle found
            if(cur[x]==true)return false;
        }
    }
    cur[u]=false; 
    return true;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>cur(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!dfs(adj,i,vis,cur))return false;
        }
        return true;
    }
};