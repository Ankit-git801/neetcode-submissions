class Solution {
public:

    bool dfs(vector<vector<int>>& adj, int u,
             vector<bool>& vis,
             vector<bool>& cur,
             stack<int>& st) {

        vis[u] = true;
        cur[u] = true;

        for (int x : adj[u]) {

            if (!vis[x]) {
                if (!dfs(adj, x, vis, cur, st))
                    return false;
            }
            else if (cur[x]) {
                return false;  // cycle
            }
        }

        cur[u] = false;
        st.push(u);

        return true;
    }

    vector<int> findOrder(int numCourses,
                           vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> cur(numCourses, false);

        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(adj, i, vis, cur, st))
                    return {};
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};