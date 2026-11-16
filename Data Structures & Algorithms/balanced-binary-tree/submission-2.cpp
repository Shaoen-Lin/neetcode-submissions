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
    bool isBalanced(TreeNode* root) {
        return (dfs(root) != -1);
    }

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        // 先 dfs 跑到底
        int left = dfs(root->left);
        int right = dfs(root->right);

        // 左右子樹只要有一個不平衡
        if (left == -1 || right == -1)
            return -1;

        // 目前節點不平衡
        if (abs(left - right) > 1)
            return -1;

        // 平衡，回傳目前子樹的高度
        return max(left, right) + 1;
    }
};
// 那就從底部一一檢查上來 root
// 只要是就會回傳以 root 當節點的 height 是多少？
// 如果不平衡了直接回傳 -1。
