# 给定一颗N叉树，如何实现N叉树的深度遍历

相对二叉树每个节点最多有两个孩子节点外，N叉树每个节点最多有N个孩子节点。本文基于对N叉树的深度遍历进一步加深对递归的理解。

## N叉树前序遍历

以leetcode第589题为例，给一个N叉树的根节点，返回节点值的前序遍历。

### 1、递归

一般来说，树的遍历通过递归实现比较简单，直接深度优先搜索遍历每个节点，若节点不为空，先将结果保存至结果集，然后继续遍历孩子节点。c++代码如下：

```
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans{};
        ans.reserve(1e4);  // 由于节点总数的范围为[0, 1e4]，预先分配内存，避免内存的动态扩展
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(Node* node, vector<int>& ans) {
        if (node == nullptr) {
            return;
        }

        ans.push_back(node->val);

        for (auto child : node->children) {
            dfs(child, ans);
        }
    }
};

// 时间复杂度O(n)，n为N叉树节点的个数
// 空间复杂度O(n)，若N叉树退化为链表，最坏情况为O(n)，平均情况下为O(logn)
```

### 2、迭代

若不使用递归，一般需要借助栈实现N叉树的迭代遍历。栈的特点是后进先出(LIFO)。若遍历访问节点的孩子，需要将后访问的孩子节点先压入栈中，先访问的孩子节点后压入栈。当弹出栈时保证是需要先访问的孩子节点。c++代码如下：

```c++
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans{};
        ans.reserve(1e4);  // 由于节点总数的范围为[0, 1e4]，预先分配内存，避免内存的动态扩展
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(Node* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        stack<Node*> stack{};
        stack.push(root);
        while (!stack.empty()) {
            root = stack.top();
            stack.pop();
            assert(root != nullptr);  // 通过断言保证访问的节点不为空，否则异常
            ans.push_back(root->val);
            for (int i = root->children.size() - 1; i >= 0; --i) {
                stack.push(root->children[i]);
            }
        }
    }
};

// 时间复杂度O(n)，n为N叉树节点的个数
// 空间复杂度O(n)，若N叉树退化为链表，此时栈的空间为O(1)，若N叉树深度为1，栈的空间为O(n)，平均情况下为O(logn)
```

















