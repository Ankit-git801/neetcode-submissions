class Solution {
public:
    vector<int> parent;
    vector<int> rank;

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

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        rank.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // email -> account index
        unordered_map<string, int> emailOwner;

        // 1. Connect accounts having common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailOwner.find(email) == emailOwner.end()) {
                    emailOwner[email] = i;
                }
                else {
                    Union(i, emailOwner[email]);
                }
            }
        }

        // 2. root -> all emails belonging to that component
        unordered_map<int, vector<string>> groups;

        for (auto& [email, index] : emailOwner) {
            int root = find(index);
            groups[root].push_back(email);
        }

        // 3. Construct answer
        vector<vector<string>> ans;

        for (auto& [root, emails] : groups) {

            sort(emails.begin(), emails.end());

            vector<string> account;

            // Name of the account
            account.push_back(accounts[root][0]);

            // Sorted emails
            for (string& email : emails) {
                account.push_back(email);
            }

            ans.push_back(account);
        }

        return ans;
    }
};