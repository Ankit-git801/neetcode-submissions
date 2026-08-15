class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<adj.size();i++){
            for(int &u:adj[i])indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++)if(indegree[i]==0)q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int &x:adj[cur]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        if(ans.size()!=numCourses)return false;
        return true;
    }
};