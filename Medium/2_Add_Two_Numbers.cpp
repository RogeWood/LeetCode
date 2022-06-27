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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *ans = NULL;
        ListNode *head;

        while(l1 || l2 || sum)
        {
            sum += ((l1)? l1->val: 0) + ((l2)? l2->val: 0); // 檢查點是否存在並加入
            ListNode *node = new ListNode(0); // 宣告一個新節點並儲存
            node->val = sum % 10;
            sum /= 10;

            if(ans) ans->next = node;
            else head = node; // 儲存起點
            ans = node;
            if(l1) l1 = l1->next; // l1 還有下一個
            if(l2) l2 = l2->next; // l2 還有下一個
        }
        return head;
    }
};
