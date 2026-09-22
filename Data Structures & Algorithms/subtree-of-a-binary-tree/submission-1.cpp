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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == nullptr)
            return true;

        // 邏輯也可以想成 root 裡面已經沒有樹可以給 subRoot 配對了
        if(root == nullptr) // 因為 nullptr 不能取 left & right
            return false;
        else if(isSametree(root, subRoot)) 
            return true;
        else 
            return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

    bool isSametree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        else if(p != nullptr && q != nullptr)
        {
            if(p->val == q->val)
            {
                if(isSametree(p->left, q->left) && isSametree(p->right, q->right))
                    return true;
            }
        }
        return false;
    }
};
