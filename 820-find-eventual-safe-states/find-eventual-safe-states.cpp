class Solution {
public:
bool dfs(int n,vector<vector<int>>& graph,vector<int>&state){
if(state[n]==1)return false;
if(state[n]==2)return true;
state[n]=1;
for(int &x:graph[n]){
    if(!dfs(x,graph,state))return false;
}
state[n]=2;
return true;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};