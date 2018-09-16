/**
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        if(!l1&&!l2)return nullptr;
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *res=new ListNode(0);
        ListNode *p3=res;
        int carry=0;
        while(carry||p1||p2)
        {
            int sum=0;
            if(carry)
                sum+=carry;
            if(p1)
                sum+=p1->val;
            if(p2)
                sum+=p2->val;
            carry=sum/10;
            sum=sum%10;
            ListNode *temp=new ListNode(sum);
            p3->next=temp;
            p3=p3->next;
            if(p1)
                p1=p1->next;
            if(p2)
                p2=p2->next;
                
        }
        return res->next;
    }
};
