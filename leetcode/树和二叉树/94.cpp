//中序遍历 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
class Solution {
public:
    vector<int> ret;
    void inTraversal(TreeNode* root) {
        if(!root) return;
        else {
            inTraversal(root->left);
            ret.push_back(root->val);
            inTraversal(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inTraversal(root);
        return ret;
    }
};