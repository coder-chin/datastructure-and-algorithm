// 层序遍历 https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

//心路历程： 前几题很简单，一顿操作猛如虎。刚看到这题，忘记怎么做了 然后查资料，以前学的是用队列的方式。 但是这题貌似不能用，因为分不清谁和谁
//在同一层
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;

        vector<TreeNode*> a, b;  //这道题比较特殊，因为需要每层单独都组成一个数组，因此不能用队列的方式
        //a 当前层  b下一层
        a.push_back(root);

        while(!a.empty()) {
            b.clear();
            vector<int> tmp; //该层结点的数据值
            for(TreeNode* node: a) {
                tmp.push_back(node->val);
                if(node->left)   b.push_back(node->left);
                if(node->right)  b.push_back(node->right);
            }
            ret.push_back(tmp);
            swap(a, b);
        }

        return ret;
    }
};