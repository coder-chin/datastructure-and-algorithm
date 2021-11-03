//后序遍历 https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
class Solution {
public:
    vector<int> ret;
    void postTraversal(TreeNode* root) {
        if(!root) return;
        else {
            postTraversal(root->left);
            postTraversal(root->right);
            ret.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postTraversal(root);
        return ret;
    }
};