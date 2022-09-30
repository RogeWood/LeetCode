/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node, int level, int tar)
    {
        if(level + 1 == tar)
        {
            node->next = node->next->next;
            return;
        }
        deleteNode(node->next, level+1, tar);
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = 0;
        ListNode* node = head;
        while(node)
        {
            len++;
            node = node->next;
        }
        if(!(len - n)) return head->next;
        
        deleteNode(head, 0, len - n);
        cout << len;
        return head;
    }
};