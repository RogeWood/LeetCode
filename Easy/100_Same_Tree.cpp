class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!(p && q)) return false;
        if(q->val != p->val) return false;
        if(!(p->left || q->left) && !(p->right || q->right)) return true;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};