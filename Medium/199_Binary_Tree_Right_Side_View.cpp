class Solution {
public:
    void travel(TreeNode* node, vector<int>& res, int level)
    {
        if(!node) return;
        
        if(level == res.size()) res.push_back(node->val); // 同階層才看的到
        
        // 先做判斷是否為 null，可以省下一次呼叫函式的次數
        if(node->right) travel(node->right, res, level+1);
        if(node->left) travel(node->left, res, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        travel(root, res, 0);
        return res;
    }
};