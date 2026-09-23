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
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;  
            int now_size = q.size();
            for(int i=0 ; i<now_size ; ++i) // 不應該用 while(!q.empty())
            {
                TreeNode* node = q.front();

                level.push_back(node->val);
                
                // 再放入 left 和 right 繼續看
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);

                q.pop();
            }
            ans.push_back(level);   
        }
        return ans;
    }
};
