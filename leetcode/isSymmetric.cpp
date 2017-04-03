struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

bool isSymmetric1(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    else if (!p || !q) return false;
    else if (p->val == q->val) {
        return isSymmetric1(p->left, q->right)
            && isSymmetric1(p->right, q->left);
    }
    else return false;
}

bool isSymmetric(TreeNode *root) {
    if (!root || (!root->left && !root->right)) return true;
    return isSymmetric1(root->left, root->right);
}
