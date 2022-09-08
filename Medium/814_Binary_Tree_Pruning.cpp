class Solution {
public:
    
    TreeNode* pruneTree(TreeNode* node)
    {
        if(!node) return NULL;
        node->left = pruneTree(node->left);
        node->right = pruneTree(node->right);
        
        if(!node->val && !node->left && !node->right)
            node = NULL;
        return node;
    }
};