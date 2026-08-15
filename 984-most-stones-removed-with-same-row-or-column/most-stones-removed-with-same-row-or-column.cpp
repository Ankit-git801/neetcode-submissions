class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int n;
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void Union(int i, int j) {
        int pi = find(i);
        int pj = find(j);

        if (pi == pj)
            return;

        if (rank[pi] < rank[pj]) {
            parent[pi] = pj;
        }
        else if (rank[pi] > rank[pj]) {
            parent[pj] = pi;
        }
        else {
            parent[pj] = pi;
            rank[pi]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }
            }
        }
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        return n - components;
    }
};