class Solution {
public:
    int countNodes(TreeNode* node) {
        if(!node) return 0;
        int sum = 1;
        if(node->right) sum += countNodes(node->right);
        if(node->left) sum += countNodes(node->left);
        return sum;
    }
}