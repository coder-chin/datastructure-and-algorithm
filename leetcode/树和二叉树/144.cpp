//前序遍历 https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
class Solution {
public:
    vector<int> ret;
    void preTraversal(TreeNode* root) {
        if(!root) return;
        else {
            ret.push_back(root->val);
            preTraversal(root->left);
            preTraversal(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preTraversal(root);
        return ret;
    }
};