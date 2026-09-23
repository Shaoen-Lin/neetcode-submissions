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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(p->val == root->val || q->val == root->val || (q->val < root->val && )

        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else if(p->val == root->val || q->val == root->val)
            return root;
        else // 一左一右
            return root;
    }
};

// 概念就是：
// 如果現在的 p 和 q 分別在 node 的左右兩邊，那 node 就是 ans
// 但 p 和 q 同時都小於 node 那就往左子樹找直到找到分叉的情況。
// 如果同時大於 node 就往右找
// 如果 p 和 q 其中一個 == node 那也是 return nodw