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
    unordered_map<int,int> search;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.empty() || inorder.empty())
            return nullptr;
        
        // 建立 Hash map 在 In 因為每次都要找 root 位置
        for(int i=0; i<inorder.size() ; ++i)
        {
            search[inorder[i]] = i;
        }

        return build(preorder, inorder,
                     0, preorder.size()-1,
                     0, inorder.size()-1);
    }

    // build subtree
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {

        if(preL > preR) // if preL == preR 代表是 leaf
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preL]);
        int root_id = search[root->val]; // 取得 root 在 inorder 的 idx，但我們晚點是要用 preorder id 去找

        // 換算成 preorder 的範圍 -> [root] [leftsize] [rightsize]
        int left_size = root_id - inL;

        root->left = build(preorder, inorder, 
                           preL+1, preL+left_size, 
                           inL, root_id-1);

        root->right = build(preorder, inorder, 
                            preL+left_size+1, preR, 
                            root_id+1, inR);

        return root;
    }
};

// 算法： [2,1,3,4]
// Pre (DLR):[1,2,3,4] -> [1] & (2) & [3,4] -> 
// In (LDR):[2,1,3,4] -> 左 1 右 2 