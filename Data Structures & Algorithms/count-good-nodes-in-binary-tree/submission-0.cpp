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
    int cnt=0;
public:
    int goodNodes(TreeNode* root) {
        dfs(root, -101);
        return cnt;
    }

    void dfs(TreeNode* root, int max_n)
    {
        if(root == nullptr)
            return;
        
        if(root->val >= max_n)
        {
            cnt++;
            max_n = root->val;
        }
            
        dfs(root->left, max_n);
        dfs(root->right, max_n);
    }


};
// 跑 DFS 每跑下去都要記錄目前跑到的最大值，如果大於最大值就 cnt++