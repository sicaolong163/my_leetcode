/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //两个方法  一个分治 一个优先队列；
   private:
    ListNode *merge(ListNode *l1,ListNode *l2)
    {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *l3=new ListNode(0);
        if(l1->val<=l2->val)
        {
            l3->next=l1;
            l1->next=merge(l1->next,l2);
        }
        else
        {
            l3->next=l2;
            l2->next=merge(l1,l2->next);
        }
        return l3->next;
    }
    ListNode* mergeKListscore(vector<ListNode*>& lists,int left,int right) 
    {
        if(left>=right)
            return lists[left];//注意递归终止的条件；
        int mid=(right-left)>>1+left;
        ListNode*l1=mergeKListscore(lists,left,mid);
        ListNode *l2=mergeKListscore(lists,mid+1,right);
        return merge(l1,l2);
    }
      struct cmp
    {
        bool operator()(ListNode *a,ListNode *b)
        {
            return a->val>b->val;
        }
        
    };
public:
    //递归分治；
    ListNode* mergeKLists1(vector<ListNode*>& lists) 
    {
        const int n=lists.size();
        if(n==0)return nullptr;
        
        return mergeKListscore(lists,0,n-1);
    }
   
    bool cmp1(ListNode *a,ListNode *b)
    {return a->val>b->val;}
    //优先队列；
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
       if(lists.size()==0)return nullptr;
        ListNode *dummy=new ListNode(0);
        ListNode *cur=dummy;
        priority_queue<ListNode *,vector<ListNode*>,cmp>q;//注意这个cmp怎么写；注意这里是结构体；一定要记住这个cmp的写法；不能写函数；
        for(auto i:lists)
            if(i)
                q.push(i);
        while(q.size())
        {
            ListNode *temp=q.top();
            q.pop();
            cur->next=temp;
            cur=cur->next;
            if(temp->next)
                q.push(temp->next);
        }
        return dummy->next; 
    }
 
};
