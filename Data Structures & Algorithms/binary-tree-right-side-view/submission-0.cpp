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
    vector<int> ans;
    queue<TreeNode*> q;

public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == nullptr)
            return {};

        q.push(root);
        while(!q.empty())
        {
            int level_size = q.size();

            for(int i=0 ; i<level_size ; ++i)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(i==level_size-1)
                {
                    ans.push_back(curr->val);
                }

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            } 
        }

        return ans;
    }
};
// 用 BFS 跑 level order traversal 然後印出每一 level 的最後一個 node 長相
