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
    int ans = 0;

public:

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int height = dfs(root);
        return ans;
    }

    int dfs(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        int l_height = dfs(root->left);
        int r_height = dfs(root->right);

        ans = max(ans, l_height+r_height);
        return max(l_height, r_height)+1;
    }
};

// 解法 1:
// 建成 graph
// BFS 跑一次找到距離 root 最遠的點
// 再從那個點跑一次最遠的距離 return

// 解法 2:
// 跑一次 DFS 把左右分支「最長的 path 」長度加起來就可以了
// 所以每個點需要去得到左右兩個分支的 path
// 此外也需要去維護一個全域變數 ans 去看能不能更新