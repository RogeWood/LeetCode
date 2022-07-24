class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *curr = head, *bighead = new ListNode(0), *smallhead = new ListNode(0);
        ListNode *big = bighead, *small = smallhead;
        while(curr)
        {
            if(curr->val < x)
            {
                small->next = curr;
                small = small->next;
            }
            else
            {
                big->next = curr;
                big = big->next;
            }
            curr = curr->next;
        }
        big->next = NULL;
        small->next = bighead->next;
        return smallhead->next;
    }
};