/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void dfs(TreeNode* node,int level,vector<int>&result){
if(!node)return;
if(result.size()<level)result.push_back(node->val);
dfs(node->right,level+1,result);
dfs(node->left,level+1,result);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        dfs(root,1,result);
        return result;
    }
};