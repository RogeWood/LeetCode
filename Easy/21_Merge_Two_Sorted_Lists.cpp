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
    static void AddNode(ListNode **newNode, ListNode **target)
    {
        *newNode = *target; // 新節點賦值
        *target = (*target)->next; // 原本的 list1 2 往下一個指
        return;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *prev = NULL;
        ListNode *head = NULL;
        
        ListNode *newNode;
        while(list1 || list2)
        {
            if(list1)
            {
                if(list2) // 1, 2 都有值，比大小
                {
                    if(list1->val < list2->val) AddNode(&newNode, &list1);
                    else AddNode(&newNode, &list2);
                }
                else AddNode(&newNode, &list1); // 只剩 1 有值
            }
            else AddNode(&newNode, &list2); // 只剩 2 有值
            
            if(prev) prev->next = newNode; // 將上一個點的下一個指向新節點
            else head = newNode; // 如果是第一個，儲存開頭
            prev = newNode; // 新節點變上一個節點
        }
        
        return head;
    }
};