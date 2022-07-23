class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans; // list 為空
        
        // BFS
        queue<TreeNode*> que;
        que.push(root);
        while(que.size())
        {
            vector<int> curr;
            int len = que.size(); // 同 level 的 node 數量
            while(len--)
            {
                TreeNode* node = que.front();
                que.pop();
                
                curr.push_back(node->val);
                
                // 加入下個 level 的 node
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};