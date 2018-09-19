/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /*
        设置一个快指针；和慢指针快指针从head开始 走过n步之后  slow从头结点开始；
        slow->next就是要删除的结点；
    */
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *dummy=new ListNode (0);
        dummy->next=head;
        ListNode *fast=head;
        while(fast&&n-->0)
        {
            fast=fast->next;
        }
        if(n>0)return nullptr;
        ListNode *slow=dummy;
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *del=slow->next;
        slow->next=del->next;
        
        delete del;
        return dummy->next;
    }
};
