/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //画个图 表示一下就可以了
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(!head||!head->next)return head;
        ListNode *dummy=new ListNode (0);
        dummy->next=head;
        ListNode *cur=dummy;
        while(cur->next&&cur->next->next)
        {
            ListNode *p1=cur->next;
            ListNode *p2=p1->next;
            p1->next=p2->next;
            p2->next=p1;
            cur->next=p2;
            cur=p1;
        }
        return dummy->next;
    }
};
