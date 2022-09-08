/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        // bfs
        queue<Node*> que;
        que.push(root);
        int n = 0, currlen = 1;
        vector<int> currlevel;
        while(que.size())
        {
            if(!currlen)
            {
                ans.push_back(currlevel);
                currlevel.clear();
                currlen = n;
                n = 0;
            }
            Node* node = que.front();
            currlevel.push_back(node->val);
            int len = node->children.size();
            for(int i = 0; i < len; i++)
            {
                que.push(node->children[i]);
                n++;
            }
            currlen--;
            que.pop();
        }
        if(currlevel.size()) ans.push_back(currlevel);
        return ans;
    }
};