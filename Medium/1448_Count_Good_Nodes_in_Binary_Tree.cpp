class Solution {
public:
    int visitChild(TreeNode *node, int maxn)
    {
        if(!node) return 0;
        int sum = 0;
        if(maxn <= node->val)
        {
            sum += 1;
            maxn = node->val;
        }
        if(node->left) sum += visitChild(node->left, maxn);
        if(node->right) sum += visitChild(node->right, maxn);
        return  sum;
    }
    
    int goodNodes(TreeNode* root) {
        return visitChild(root, root->val);
    }
};