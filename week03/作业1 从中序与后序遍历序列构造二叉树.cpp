class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& inorder, int inLeft, int inRight,
        vector<int>& postorder, int postLeft, int postRight) {
        if (postLeft > postRight) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postRight]);
        assert(root != nullptr);

        int cnt = 0;  // 获取下一个后续遍历的空间个数
        while (postorder[postRight] != inorder[inLeft + cnt]) {
            ++cnt;
        }

        root->left = buildTree(inorder, inLeft, inLeft + cnt - 1, postorder, postLeft, postLeft + cnt - 1);
        root->right = buildTree(inorder, inLeft + cnt + 1, inRight, postorder, postLeft + cnt, postRight - 1);

        return root;
    }
};