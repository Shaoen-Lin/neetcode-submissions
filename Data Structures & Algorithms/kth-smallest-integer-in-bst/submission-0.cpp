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

// 這題是在做 Inorder Traversal 走 k 個數字
public:

    int ans;

    int kthSmallest(TreeNode* root, int k) {
        In(root, k);
        return ans;
    }

    void In(TreeNode* node, int& k)
    {
        if(node == nullptr)
            return;

        // left
        In(node->left, k);

        if(k == 1)
        {
            k--;    // 把 k 減成 0 讓後面不要把 ans 又洗掉
            ans = node->val;
            return;  // 不要繼續往後走了
        }
        // 數自己 -1 
        k--;
        
         // right
        In(node->right, k);

    }
};
