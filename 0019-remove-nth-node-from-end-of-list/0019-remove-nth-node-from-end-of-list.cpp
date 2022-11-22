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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        
        ListNode *t=head;
        int count = 0 ;
        while(t)
        {
            t=t->next;
            count++;
        }
        
        if(n>count || n==0)
            return head;
        else if(count==n)
        {
            t=head->next;
            head->next=nullptr;
            delete(head);
            return t;
        }else if(n==1){
            t=head;
            while(t->next->next)
                t=t->next;
            ListNode *p=t->next;
            t->next=nullptr;
            delete(p);
            return head;
        }
        
        ListNode *dummy=new ListNode(0),*q=dummy;
        int x=n-1;
        dummy->next=head;
        t=head;
        while(x--)
        t=t->next;
        while(t->next)
        {
            t=t->next;
            q=q->next;
        }
        
        t=q->next;
        q->next=q->next->next;
        delete(t);
        return head;
    }
};