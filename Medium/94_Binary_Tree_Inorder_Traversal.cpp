class Solution {
public:
    
    // Indor: 左->中->右
    void visitNode(TreeNode* node, vector<int>& ans)
    {
        if(!node) return;
        if(node->left) visitNode(node->left, ans);
        ans.push_back(node->val);
        if(node->right) visitNode(node->right, ans);
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        visitNode(root, ans);
        return ans;
    }
};