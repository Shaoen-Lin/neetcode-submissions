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
private:
    int ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }

    void inOrder(TreeNode* root, int& k) // 注意 k 要是 pass by reference 不然會一直都是 1
    {
        if(root == nullptr)
            return;
        
        inOrder(root->left, k);
        k--;
        if(k==0)
            ans = root->val;
        inOrder(root->right, k);
    }
};

// 這題是在做 Inorder Traversal 走 k 個數字