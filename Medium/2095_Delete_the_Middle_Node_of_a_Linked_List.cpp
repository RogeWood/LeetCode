class Solution {
public:
    int findLen(ListNode *node)
    {
        if(!node->next) return 1;
        return findLen(node->next) + 1;
    }

    void removeNode(ListNode *node, int deep)
    {
        if(deep == 1)
        {
            node->next = node->next->next;
            return;
        }
        removeNode(node->next, deep-1);
        return;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        removeNode(head, findLen(head)/2);
        return head;
    }
};