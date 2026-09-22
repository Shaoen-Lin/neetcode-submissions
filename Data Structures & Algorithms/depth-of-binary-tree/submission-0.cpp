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
    int maxDepth(TreeNode* root) {
        // if(root != nullptr)
        //     return 0;
        // else if(root->left == nullptr && root->right == nullptr) 
        // {
        //     return 1;
        // }
        // return max(maxDepth(root->left), maxDepth(root->right));

        if(root == nullptr)
            return 0;
        else 
        {
            return 1+max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};

// 從 0 開始算 root，左子是 2n+1 右子是 2n+2
