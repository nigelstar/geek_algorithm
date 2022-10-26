class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        dfs(root->right);
        sum_ += root->val;
        root->val = sum_;
        dfs(root->left);
    }

private:
    int sum_ = 0;
};