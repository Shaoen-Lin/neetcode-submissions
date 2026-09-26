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
    bool isValidBST(TreeNode* root) {

        // 背：nullptr 一定是 BST
        if(root == nullptr) 
            return true;
        
        return check(root, INT_MAX, INT_MIN);
    }

    bool check(TreeNode* node, int upper, int lower)
    {
        // 注意，會遞迴的 function 都要注意要寫終止條件！ 
        // 然後 leaf 也要去檢查，只有 null 可以不檢查。
        if(node==nullptr)
            return true;

        if(lower < node->val && node->val < upper)
            return (check(node->left, node->val, lower) && 
                    check(node->right, upper, node->val));
        else 
            return false;
    }
};
